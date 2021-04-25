#include <string>
#include <vector>

using namespace std;

bool isValid(string p){
    stack<char> s;
    for(auto c: p){
        if(c=='(') s.push('(');
        else if(c==')'){
            if(s.empty() || s.top() != '(') return 0;
            else s.pop();
        }
    }
    
    return s.empty();
}
string reverse(string p){
    string res="";
    for(auto c : p){
        if(c=='(') res+=')';
        else if (c==')') res +='(';
    }
    return res;
}

string solution(string p){
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
            u = p.substr(0,i);
            v = p.substr(i,p.length());
            break;
        }
    }
    if(isValid(u)){
        v = solution(v);
    }
    else{
        v = "(" + solution(v) + ")";
        u = reverse(u.substr(1,u.length()-2));
        return v+u;
    }
    return u+v;
}

