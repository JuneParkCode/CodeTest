#include <string>
#include <vector>
#include <iostream>

using namespace std;


unsigned long long strToBit(string s)
{
    unsigned long long n = 0;
    for(char c : s)
    {
        if(c=='1')
        {
            n+=1;
        }
        n = n<<1;
    }
    return n;
}
unsigned long long find_mask(const unsigned long long mask, unsigned long long n)
{
    while(n>0)
    {
        
    }
}


vector<string> solution(vector<string> strings) 
{
    vector<string> answer;
    const unsigned long long _110 = strToBit("110");
    const unsigned long long _111 = strToBit("111");
    for(string s : strings)
    {
        unsigned long long n = strToBit(s);
        {
            find_mask();
        }
    }
    return answer;
}
