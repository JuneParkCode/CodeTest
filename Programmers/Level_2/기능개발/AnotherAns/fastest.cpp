#include <string>
#include <vector>

using namespace std;

/*
loop 최소화한 버전.
가장 빠르고 효율적이다.
*/

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    const int SIZE =progresses.size();
    vector<int> answer;
    int curDay = 0;
    int count = 0;
    int idx = 0;
    while(idx < SIZE){
        int leftDays = 100 -  progresses[idx] - speeds[idx]*curDay;
        int needDays = leftDays / speeds[idx] + (leftDays%speeds[idx] != 0);
        idx++;
        if(leftDays <= 0){
            count++;
            if(idx==SIZE)   answer.push_back(count);
            continue; 
        }
        else{
            if(count) answer.push_back(count);
            if(idx==SIZE)   answer.push_back(1);
            curDay += needDays;
            count = 1;
        }
    }

    return answer;
}