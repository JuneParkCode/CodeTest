#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(auto c:s){
        if(c=='-' ||c=='+') continue;
        answer += c-'0';
        answer *= 10;
    }
    return answer/10 * (s[0]=='-'?-1:1);
}

int solution(string s) {
    int answer = stoi(s); // 문자열 변경
    return answer;
}

