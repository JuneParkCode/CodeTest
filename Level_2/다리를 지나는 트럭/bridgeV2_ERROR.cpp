//ver INPUT
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int length, int weight, vector<int> truck_weights) {
    int curWeight = 0;
    int i =0;
    int tW = 0;
    int inTime = 0;                   // time : 현재 차의 입고 시간
    int outTime;
    queue<pair<int,int>> bridge;    // weight , 출고 시간
    while(i<truck_weights.size()){
        tW=truck_weights[i];
        inTime++;
        if(tW+curWeight <= weight){
            outTime = inTime+length;
            bridge.push(make_pair(tW,outTime)); 
            curWeight += tW;
            i++;
        }
        else{// 앞 차가 나올 때 까지 대기
            curWeight -= bridge.front().first;
            if(inTime != bridge.front().second +1 )
                inTime = bridge.front().second-1;
            else
                inTime--;
            bridge.pop();
        }
    }
    return bridge.back().second;
}