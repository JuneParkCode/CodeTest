#include <string>
#include <vector>
#include <algorithm>

#define DIGITS 4
using namespace std;
// a<b일때 1
bool compareStr(string &a, string &b)
{
    return stoi(a+b) > stoi(b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_nums;
    bool checker = 0;
    for(int n : numbers)
    {
        checker = checker ? 1 : n;
        s_nums.push_back(to_string(n));
    }
    sort(s_nums.begin(),s_nums.end(),compareStr);
    for(int i=0;i<s_nums.size(); ++i)
    {
        answer += s_nums[i];
    }
    return checker? answer : "0";
}