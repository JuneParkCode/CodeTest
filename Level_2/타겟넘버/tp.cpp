#include <string>
#include <vector>

using namespace std;
void find_set(const vector<int> &numbers,int& counts,int result, const int idx, const int target)
{
    if(idx<numbers.size())
    {
        find_set(numbers,counts,result+numbers[idx],idx+1,target);
        find_set(numbers,counts,result-numbers[idx],idx+1,target);
    }
    else
    {
        counts += (result == target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    find_set(numbers,answer,0,0,target);
    return answer;
}