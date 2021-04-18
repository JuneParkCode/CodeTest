#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// weight : 다리 최대 하중
// length : 다리를 지나는데 걸리는 시간
void printQ(queue<int> q){
    int weight = 0;
    while(!q.empty()){
        weight += q.front();
        cout << q.front() << " ";
        q.pop();
    }
    cout << "w: "<<weight<<endl;
}

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
        printQ(bridge);
        int tW = trucks.front();
        curWeight -= bridge.front();
        if(curWeight + tW <= weight){
            bridge.push(tW);
            curWeight += tW;
            trucks.pop();
        }
        else{
            bridge.push(0);
        }
        bridge.pop();
        answer++;
    }while(curWeight>0);
    
    return answer;
}