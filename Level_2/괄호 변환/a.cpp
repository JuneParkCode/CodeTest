#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string p){
    stack<char> s;
    for(auto c: p){
        if(c=='(') s.push('(');
        else if(c==')'){
            if(s.top() == '(') s.pop();
            else return 0;
        }
    }
    return s.empty();
}
string reverse(string p){
    stack<char> s;
    string res="";
    for(auto c : p){
        s.push(c);
    }
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    return res;
}

string solution(string p) {
    if(p=="") return p;
    string u,v;
    int count_open=0;
    int count_close=0;
    int i = 0;
    for(auto c : p){
        i++;
        if(c=='(') count_open++;
        else if(c==')') count_close++;
        if(count_open==count_close){
            u = p.substr(p[0],i); 
            v = p.substr(p[i],p.length());
            break;
        }
    }
    if(!isValid(u)){
        string res = "";
        v = solution(v);
        u = "(" + reverse(u.substr(1,u.length()-2)) + ")";
    }
    return u+v;
}