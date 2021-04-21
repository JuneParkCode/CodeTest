#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
// 뒤쪽에 더 우선순위가 높은 문서가 있으면 뒤로 미룸..
// 3 2 1 3 2 -->  0 3 4 1 2
int solution(vector<int> priorities, int location) {
    int answer =0;
    int max = 0;
    vector<pair<int,int>> v;
    for(int i=0; i<priorities.size(); i++)
        v.push_back(make_pair(i,priorities[i]));
    for(int i=0;; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i].second < v[j].second){
                v.push_back(v[i]);
                v[i] = make_pair(0,0);
                break;
            }
        }
        if(v[i] != make_pair(0,0)){
            answer++;
            if(v[i].first == location) return answer;
        }
    }
}