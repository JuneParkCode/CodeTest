#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {  
    string answer = "";
    int interval = 'a' - 'z'-1;
    for(char c : s){
        int val = int(c);
        int A='A';   //a,A 사이에 특문이 있음...
        int a='a';
        if('a'<=val && val<='z')
            A=a;
        else if (c==' '){
            answer += char(val);
            continue;
        }
        val = (val+n-A)%interval +A;
        answer += char(val);
    }
    return answer;
}