#include <string>
#include <vector>

using namespace std;
int checkDifBitNumber(long long a, long long b)
{
    int dif = 0;
    while(b>0)
    {
        if((b&1) != (a&1))
        {
            ++dif;
        }
        a=a>>1,b=b>>1;
    }
    return dif +((b&1) != (a&1));
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number :numbers)
    {
        int dif = 3;
        long long n = number;
        while(dif>2)
        {
            n++;
            dif = checkDifBitNumber(number,n);
        }
        answer.push_back(n);
    }
    return answer;
}