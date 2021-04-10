#include <string>
using namespace std;
int solution(string dartResult) {
    int answer = 0;
    int temp=0,prev=0;
    bool isNumber=false;
    string s="";
    for(auto c : dartResult){
        if('0'<=c&&c<='9'){ //숫자인 경우
            isNumber = true;
            s += c;
        }
        else{
            if(isNumber){
                answer += prev;
                prev = temp;
                temp = stoi(s);
                s="";
            }
            if(c=='S');
            else if(c=='D') temp = temp * temp;
            else if(c=='T') temp = temp * temp * temp;
            else if(c=='*') temp *=2, prev*=2;
            else if(c=='#') temp = -temp;
            isNumber = false;
        }
    }
    return answer += temp + prev;
}