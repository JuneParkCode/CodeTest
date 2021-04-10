#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compC(char a,char b){  /****/
    return a>b;
}   // 내 풀이
string solution(string s){
    string answer = "";
    vector<char> v;
    for(auto c :s)
        v.push_back(c);
    sort(v.begin(),v.end(),compC);
    for(auto c:v)
        answer+=c;
    return answer;
}
//best
string solution(string s){
    sort(s.begin(),s.end(),compC);  // char타입이 아니라 string으로 접근해서 안됐던 것 같음...
    return s;
}