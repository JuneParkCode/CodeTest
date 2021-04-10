#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = arr[0];
    answer.push_back(prev);
    for(auto n : arr){
        if(prev == n)
            continue;
        else{
            prev = n;
            answer.push_back(prev);
        }
    }

    return answer;
}