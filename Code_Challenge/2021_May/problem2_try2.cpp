#include <string>
#include <vector>

using namespace std;
vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    for(long long number :numbers)
    {
        const unsigned long long N = number;
        unsigned long long n=number,t = number;
        long long count = 1;
        while(t>0)
        {
            if( (t&1) == 0)
            {
                n += count - count/2;
            }
            t = t>>1;
            count *= 2;
            if(n>N) break;
        }
        if(N == n)
        {
            n = N + count - count/2;
        }
        answer.push_back(n);
    }
    return answer;
}