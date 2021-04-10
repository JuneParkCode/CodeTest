#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//간결한게 참 괜찮은 식인듯
int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    for(answer=0; (budget=budget-d[answer]) >= 0 && answer<d.size(); answer++);
    return answer;
}

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(),d.end());
    for(auto n : d){
        sum += n;
        if(sum>budget)
            sum -=n;
        else
            answer++;
        if(sum==budget)
            break;
    }
    return answer;
}