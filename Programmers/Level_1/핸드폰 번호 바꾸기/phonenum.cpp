#include <string>
#include <vector>

using namespace std;

//better ans
string solution(string phone_number) {
    for(int i=0;i<(phone_number.size()-4);i++)
        phone_number[i] = '*';
    return phone_number;
}
//my ans
string solution(string phone_number) {
    string answer = "";
    int l = phone_number.length();
    for(int i=0;i<(l-4);i++)
        answer += '*';
    for(int i=l-4;i<l;i++)
        answer += phone_number[i];
    return answer;
}