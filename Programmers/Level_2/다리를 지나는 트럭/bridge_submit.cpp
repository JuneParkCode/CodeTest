#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
테스트 1 〉	통과 (0.02ms, 3.87MB)
테스트 2 〉	통과 (0.16ms, 3.95MB)
테스트 3 〉	통과 (0.01ms, 3.93MB)
테스트 4 〉	통과 (0.10ms, 3.77MB)
테스트 5 〉	통과 (0.95ms, 3.96MB)
테스트 6 〉	통과 (0.25ms, 3.94MB)
테스트 7 〉	통과 (0.02ms, 3.96MB)
테스트 8 〉	통과 (0.01ms, 3.96MB)
테스트 9 〉	통과 (0.04ms, 3.78MB)
테스트 10 〉	통과 (0.01ms, 3.89MB)
테스트 11 〉	통과 (0.01ms, 3.71MB)
테스트 12 〉	통과 (0.01ms, 3.84MB)
테스트 13 〉	통과 (0.02ms, 3.81MB)
테스트 14 〉	통과 (0.01ms, 3.96MB)
*/
int solution(int length, int weight, vector<int> truck_weights) {
    int answer =0;
    int curWeight = 0;
    queue<int> trucks;
    for(auto t : truck_weights)
        trucks.push(t);
    
    queue<int> bridge;
    for(int i=0; i<length; i++)
        bridge.push(0);
    do{
        int tW = trucks.front();
        curWeight -= bridge.front();
        if(curWeight + tW <= weight && !trucks.empty()){
            bridge.push(tW);
            curWeight += tW;
            trucks.pop();
        }
        else
            bridge.push(0);
        bridge.pop();
        answer++;
    }while(curWeight>0);
    
    return answer;
}