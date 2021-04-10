#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
Fastest!!!
테스트 1 〉	통과 (16.50ms, 17.7MB)
테스트 2 〉	통과 (27.07ms, 25.4MB)
테스트 3 〉	통과 (31.65ms, 30.1MB)
테스트 4 〉	통과 (32.68ms, 32.6MB)
테스트 5 〉	통과 (41.11ms, 32.5MB)
*/
string MyLastsolution(vector<string> participant, vector<string> completion){
    unordered_map<string,int> s;
    for(auto c:completion)
        s[c]++;
    for(auto p:participant)
        if(--s[p] < 0) return p;
}
//vector sort 속도가 생각보다 빠르다. 
//n이하인듯... 

/*
테스트 1 〉	통과 (65.27ms, 21.6MB)
테스트 2 〉	통과 (119.89ms, 31.1MB)
테스트 3 〉	통과 (138.68ms, 36.9MB)
테스트 4 〉	통과 (122.60ms, 40MB)
테스트 5 〉	통과 (114.07ms, 40MB

2n
*/
string My1Solution(vector<string> participant, vector<string> completion){
    unordered_set<string> s;
    map<string,int> isDuplicate;
    for(auto c:completion){
        s.insert(c);
        isDuplicate[c]++;
    }
    for(auto p:participant){
        if(s.erase(p)==0 && --isDuplicate[p] <= 0 ){
            std::cout << p;
            return p;
        }
    }
    return "";
}
/*
테스트 1 〉	통과 (94.59ms, 21.6MB)
테스트 2 〉	통과 (161.75ms, 31.1MB)
테스트 3 〉	통과 (218.53ms, 36.9MB)
테스트 4 〉	통과 (187.46ms, 40.1MB)
테스트 5 〉	통과 (268.13ms, 40.1MB)
*/

string My0solution(vector<string> participant, vector<string> completion) {
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
/*
#include <algorithm>
테스트 1 〉	통과 (37.63ms, 14.3MB)
테스트 2 〉	통과 (58.39ms, 19.8MB)
테스트 3 〉	통과 (72.56ms, 23.3MB)
테스트 4 〉	통과 (80.18ms, 25.4MB)
테스트 5 〉	통과 (72.40ms, 25.3MB)

n
*/
string BestSolution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
    //return answer;
}