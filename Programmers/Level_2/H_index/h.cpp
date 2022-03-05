#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    map<int,int> citationMap;
    for(int n : citations)
    {
        for(int i=0; i<n; ++i)
        {
            ++citationMap[i];
        }
    }
    for(auto m : citationMap)
    {
        if(m.first > m.second)
        {
            break;
        }
        answer = m.second;
    }
    return answer;
}