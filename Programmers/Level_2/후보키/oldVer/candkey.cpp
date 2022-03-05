#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
/*
최소성, 유일성을 갖는 튜플 조합의 갯수를 구하여라.
*/

/*
-생각
 1. 튜플의 다양한 조합을 무작위로 다 대입해야하는가?
 1-1. 그렇다면 튜플의 종류를 일일히 만드는 과정은 어떻게 할 것인가?
 1-2. 갯수를 중심으로 풀어나가야함. BFS?
*/
bool isUnique(set<int> q, vector<vector<string>> &table){
    // q열의 원소들만 조합
    set<string> checkSet;
    for(vector<string> element : table){
        string newStr = "";
        for(int i : q){
            newStr += element[i];
        }
        checkSet.insert(newStr);
    }
    return checkSet.size() == table.size();
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    set<set<int>> q;
    set<int> notuniqueSet;
    set<set<int>> uniqueSet;
    for(int i=0; i<relation[0].size(); i++){
        if(!isUnique({i},relation)){
            notuniqueSet.insert({i});
            q.insert({i});
        }
        else{
            uniqueSet.insert({i});
        }
    }
    auto it = q.begin();
    while(it != q.end()){
        set<int> s = *it;
        if(s.size() >= notuniqueSet.size()) break;
        for(int n : notuniqueSet){
            set<int> newSet = s;
            if(*(--newSet.end()) >= n) continue;
            newSet.insert(n);
            if(!isUnique(newSet,relation)){
                q.insert(newSet);
            }
            else{
                uniqueSet.insert(newSet);
            }
        }
        ++it;
    }
    /*
    for(auto e : uniqueSet){
        for(auto n : e){
            cout << n << " ";
        }
        cout <<endl;
    }
    */
    return uniqueSet.size();
}

int main(){
    vector<vector<string>> s = {{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};
    cout << solution(s);
}