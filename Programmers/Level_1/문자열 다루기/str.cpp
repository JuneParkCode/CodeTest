#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(string s) {
    if(!(s.length() ==4 || s.length() ==6)) return false;
    for(auto c :s)
        if(!('0'<=c&&c<='9'))
            return false;
    return true;
}
// best ans..
bool solution(string s) {
    for (int i = 0; i < s.size(); i++)
        if (!isdigit(s[i])) // 이런게 있네
            return false;
    return s.size() == 4 || s.size() == 6 ? true : false;
}