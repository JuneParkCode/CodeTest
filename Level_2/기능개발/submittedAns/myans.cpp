#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
내 생각에 이것도 좀 비효율적인 방법인 것 같다.
다른 방법이 있을까?
*/
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    const int SIZE =progresses.size();
    vector<int> answer;
    vector<int> release(SIZE,0);
    int dayCount = 0;
    while(release[SIZE-1]==0){
        ++dayCount;
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
                }
            }
        }   
    }
    int count = 0;
    for(int i=0;i<SIZE;i++){
        if(i!=0 && release[i] != release[i-1] && i!=(SIZE-1)){
            answer.push_back(count);
            count = 1;
        }
        else if(i==(SIZE-1)){
            if(release[i] != release[i-1]){
                answer.push_back(count);
                answer.push_back(1);
            }
            else{
                answer.push_back(++count);
            }
        }
        else
            count++; 
    }
    
    return answer;
}