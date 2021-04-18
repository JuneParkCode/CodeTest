#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
졸라빠름
*/
int solution(int length, int weight, vector<int> truck_weights) {
    int curWeight = 0;
    int i =0;
    int tW = 0;
    int inTime = 1;                   // time : 현재 차의 입고 시간
    int outTime;
    queue<pair<int,int>> bridge;    // weight , 출고 시간
    while(i<truck_weights.size()){
        tW=truck_weights[i];
        if(tW+curWeight <= weight){ // 다리에 입고
            outTime = inTime+length;
            bridge.push(make_pair(tW,outTime)); 
            curWeight += tW;
            i++;
            inTime++;
        }
        else{// 맨 앞 차 출고 시점으로 가서 다시 검증해보자....
            curWeight -= bridge.front().first;
            if(inTime > bridge.front().second)
                inTime = inTime;
            else
                inTime = bridge.front().second;
            bridge.pop();
        }
    }
    return bridge.back().second;
}