#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<string,int> tupleMap;
    string num = "";
    for(char c : s)
    {
        // number 일 때
        if(c!='{' && c!='}' && c!=',')
        {
            num += c;
        }
        // push 해야하는 상황
        else if( (c==',' || c=='}') && num.length() > 0)
        {
            ++tupleMap[num];
            num = "";
        }
    }
    vector<pair<string,int>> temp (tupleMap.begin(),tupleMap.end());
    sort(temp.begin(),temp.end(),cmp);
    for(auto p : temp)
    {
        answer.push_back(stoi(p.first));
    }
    return answer;
}