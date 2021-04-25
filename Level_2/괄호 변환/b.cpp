#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string p){
    int count = 0;
    for(auto c: p){
        if(c=='(') count++;
        else count--;
        if(count<0) return false;
    }
    return count == 0;
}

string solution(string p){
    if(p=="") return p;
    string u,v;
    int count = 0;
    for(int i=0; i<p.size();i++){
        if(p[i]=='(') count++;
        else if(p[i]==')') count--;
        if(count==0){
            u = p.substr(0,i);
            v = p.substr(i,p.length());
            break;
        }
    }
    if(isValid(u))
        return u + solution(v);
    else{
        for(char &c : u) c= (c==')'?'(':')');
        return "(" + solution(v) + ")" +u.substr(1,u.length()-2);
    }
}

