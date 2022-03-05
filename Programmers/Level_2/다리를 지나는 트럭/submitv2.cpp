#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
테스트 1 〉	통과 (0.02ms, 3.94MB)
테스트 2 〉	통과 (0.15ms, 3.97MB)
테스트 3 〉	통과 (0.01ms, 3.95MB)
테스트 4 〉	통과 (0.11ms, 3.95MB)
테스트 5 〉	통과 (1.04ms, 3.9MB)
테스트 6 〉	통과 (0.27ms, 3.96MB)
테스트 7 〉	통과 (0.02ms, 3.97MB)
테스트 8 〉	통과 (0.01ms, 3.93MB)
테스트 9 〉	통과 (0.05ms, 3.96MB)
테스트 10 〉	통과 (0.01ms, 3.96MB)
테스트 11 〉	통과 (0.01ms, 3.94MB)
테스트 12 〉	통과 (0.01ms, 3.93MB)
테스트 13 〉	통과 (0.02ms, 3.95MB)
테스트 14 〉	통과 (0.01ms, 3.94MB)
똑같애
*/
int solution(int length, int weight, vector<int> truck_weights) {
    int answer =0;
    int curWeight = 0;
    int i =0;
    queue<int> bridge;
    for(int i=0; i<length; i++)
        bridge.push(0);
    do{
        int tW = truck_weights[i];
        curWeight -= bridge.front();
        if(curWeight + tW <= weight && i < truck_weights.size()){
            bridge.push(tW);
            curWeight += tW;
            i++;
        }
        else
            bridge.push(0);
        bridge.pop();
        answer++;
    }while(curWeight>0);
    
    return answer;
}