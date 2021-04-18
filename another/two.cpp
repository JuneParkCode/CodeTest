#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool checker(string s){
    stack<char> q;
    if(s.empty()) return 0;
    for(int i=0; i<s.length(); i++){
        char c=s[i];
        if(c=='{')
            q.push(c);
        else if (c == '[')
            q.push(c);
        else if (c == '(')
            q.push(c);
        if(q.empty()) return 0;
        if (c == '}'){
            if(q.top() != '{')
                return 0;
            else
                q.pop();
        }
        else if (c == ']'){
            if(q.top() != '[')
                return 0;
            else
                q.pop();
        }
        else if (c == ')'){
            if(q.top() != '(')
                return 0;
            else
                q.pop();
        }
    }
    if(!q.empty()) return 0;
    else return 1;
}

int solution(string s) {
    int answer = 0;
    string newS ="";
    for(int i=0; i<s.length()-1; i++){
        newS = s.substr(i,s.length()) + s.substr(0,i);
        answer += checker(newS);
    }
    return answer;
}