#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
/*
내 코드가 best 코드보다 더 빠름 O(2n+m)
// 첫 코드에서 반복되는 부분을 줄였음 4n --> 2n
데이터는 조금 더 잡아먹음 ...
테스트 1 〉	통과 (0.02ms, 3.88MB)
테스트 2 〉	통과 (0.03ms, 3.95MB)
테스트 3 〉	통과 (0.67ms, 4.11MB)
테스트 4 〉	통과 (2.88ms, 6.46MB)
테스트 5 〉	통과 (6.51ms, 9.86MB)
테스트 6 〉	통과 (0.10ms, 3.77MB)
테스트 7 〉	통과 (0.32ms, 3.97MB)
테스트 8 〉	통과 (2.86ms, 6.5MB)
테스트 9 〉	통과 (6.60ms, 9.93MB)
테스트 10 〉	통과 (2.45ms, 6.32MB)
테스트 11 〉	통과 (2.47ms, 6.53MB)
테스트 12 〉	통과 (3.56ms, 7.9MB)
테스트 13 〉	통과 (4.22ms, 8.43MB)
테스트 14 〉	통과 (0.02ms, 3.96MB)
테스트 15 〉	통과 (0.74ms, 5.26MB)
테스트 16 〉	통과 (0.33ms, 4.43MB)
테스트 17 〉	통과 (0.89ms, 5.31MB)
테스트 18 〉	통과 (0.31ms, 4.52MB)
테스트 19 〉	통과 (0.14ms, 3.96MB)
테스트 20 〉	통과 (0.56ms, 4.78MB)
테스트 21 〉	통과 (0.80ms, 6.29MB)
테스트 22 〉	통과 (2.97ms, 9.78MB)
테스트 23 〉	통과 (1.68ms, 9.64MB)
테스트 24 〉	통과 (3.09ms, 9.52MB)
테스트 25 〉	통과 (0.01ms, 3.77MB)
테스트 26 〉	통과 (0.01ms, 3.97MB)
테스트 27 〉	통과 (0.01ms, 3.93MB)
*/
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int,int,greater<int>> playerStageMap;
    set<pair<double,int>> failureRatio;
    for(auto p : stages)
        playerStageMap[p] +=1;
    int acc =0;
    for(int i=N+1; i>=0; i--){
        int s = playerStageMap[i] == NULL ? 0 : playerStageMap[i];
        int c = acc += s;
        double fR = 1- (double)s/c;
        if(i == N+1 || i==0) continue;
        failureRatio.insert(make_pair(fR,i));
    }
    for(auto s : failureRatio)
        answer.push_back(s.second);
    return answer;
}
