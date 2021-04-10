#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// best ans !!
// sort를 이용하는 방법!! 
int i;
bool compare(string a,string b){
    return a[i]==b[i] ? a<b : a[i]<b[i];
}

/*
테스트 1 〉	통과 (0.01ms, 3.89MB)
테스트 2 〉	통과 (0.01ms, 3.96MB)
테스트 3 〉	통과 (0.03ms, 3.95MB)
테스트 4 〉	통과 (0.04ms, 3.96MB)
테스트 5 〉	통과 (0.02ms, 3.82MB)
테스트 6 〉	통과 (0.04ms, 3.96MB)
테스트 7 〉	통과 (0.02ms, 3.78MB)
테스트 8 〉	통과 (0.02ms, 3.97MB)
테스트 9 〉	통과 (0.02ms, 3.96MB)
테스트 10 〉	통과 (0.06ms, 3.98MB)
테스트 11 〉	통과 (0.01ms, 3.94MB)
테스트 12 〉	통과 (0.06ms, 3.83MB)
거의 모든 경우에서 더 빠름... 중복도 처리 가능
*/
vector<string> solution(vector<string> strings, int n){
    i=n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}

// my ans
/*
테스트 1 〉	통과 (0.01ms, 3.95MB)
테스트 2 〉	통과 (0.01ms, 3.95MB)
테스트 3 〉	통과 (0.04ms, 3.95MB)
테스트 4 〉	통과 (0.03ms, 3.95MB)
테스트 5 〉	통과 (0.02ms, 3.97MB)
테스트 6 〉	통과 (0.04ms, 3.95MB)
테스트 7 〉	통과 (0.02ms, 3.96MB)
테스트 8 〉	통과 (0.02ms, 3.97MB)
테스트 9 〉	통과 (0.12ms, 3.96MB)
테스트 10 〉	통과 (0.05ms, 3.96MB)
테스트 11 〉	통과 (0.02ms, 3.73MB)
테스트 12 〉	통과 (0.05ms, 3.96MB)
*/
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    set<pair<char,string>> ansSet;
    for(auto s : strings)
        ansSet.insert(make_pair(s[n],s));
    for(auto s: ansSet)
        answer.push_back(s.second);
    return answer;
}