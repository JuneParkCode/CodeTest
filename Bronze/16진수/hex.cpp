#include <iostream>
#include <string>
using namespace std;

long long hex2int(string& s)
{
    int l = s.length() -1 ;
    long long sum = 0;
    long long x = 1;
    for(int i = 0; i<=l; i++)
    {
        if( s[l-i] >= '0' && s[l-i] <= '9')
        {
            sum += x * (s[l-i] - '0');
        }
        else if( s[l-i] >= 'A' && s[l-i] <= 'F')
        {
            sum += x * (s[l-i] - 'A' + 10);
        }
        else
        {
            return -1;
        }
        x*=16;
    }
    return sum;
}

int main()
{
    string s;
    cin >> s;
    cout << hex2int(s);
    return 0;
}