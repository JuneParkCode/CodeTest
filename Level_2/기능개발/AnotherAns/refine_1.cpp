#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
중첩 For 문이 마음에 들지 않는다.
본래 스택/큐 문제이기에 그 방법을 고심해봐야할듯.
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    const int SIZE =progresses.size();
    vector<int> answer;
    vector<int> release(SIZE,0);
    int dayCount = 0;
    while(release[SIZE-1]==0){
        ++dayCount;
        int count =0;
        for(int i=0; i<SIZE; i++){
            if(release[i]) continue;
            progresses[i] += speeds[i];
            if(progresses[i] >= 100){
                bool check = 0;
                for(int j=0; j<i; j++){
                    if(progresses[j] < 100){
                        check = 1;
                        break;
                    }
                }
                if(!check){
                    release[i] = dayCount;
                    count++;
                }
            }
        }   
        if(count) answer.push_back(count);  //release date에 한꺼번에 올라가므로...
    }
    
    return answer;
}