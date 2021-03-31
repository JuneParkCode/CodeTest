#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> isDuplicate;
    unordered_set<string> complete;
    for(auto p : participant){
        complete.insert(p);
        isDuplicate[p] = isDuplicate[p] + 1;
    }
    for(auto c : completion){
        if(isDuplicate[c]==1)
            complete.erase(c);
        else{
            isDuplicate[c] = isDuplicate[c]-1;
            continue;
        }
    }
    answer =  *complete.begin();
    return answer;
}