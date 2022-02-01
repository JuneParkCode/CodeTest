#include <iostream>
#include <string>

using namespace std;

class BigInt
{
private:
    string N;
public:
    BigInt(string input)
    {
        for(const char n : input)
        {
            if( n <'0' || n >'9'){
                if(n=='-') continue;
                cout<<"ERROR";
                return;
            }
        }
        N = input;
    }
    string operator + (BigInt& x)
    {
        const string l = N.length() >= x.N.length() ? N : x.N;
        const string r =  N.length() >= x.N.length() ? x.N : N;
        int lLength = l.length();
        int rLength = r.length();
        int res = 0;
        int up = 0;
        string result = "";
        for(int i = 0; i < lLength; i++)
        {
            int sum = l[lLength - i -1] - '0' + up;
            if(i<rLength)
            {
                sum += r[rLength - i -1] - '0';
            }
            up = sum/10;
            res = sum%10;
            result = to_string(res) + result;
        }
        if(up != 0){
            result = to_string(up) + result;
        }
        return result;
    }
    bool operator < (BigInt& x){
        const string l = N;
        const string r = x.N;
        if(l.length() < r.length())
        {
            return 1;
        } 
        else if(l.length() > r.length())
        {
            return 0;
        }
        for(int i=0; i<l.length(); i++ )
        {
            if(l[i] < r[i])
            {
                return 1;
            }
            else if(l[i] > r[i])
            {
                return 0;
            }
        }
        return 0;
    }
    string operator - (BigInt& x)
    {
        const string l = N.length() >= x.N.length() ? N : x.N;
        const string r =  N.length() >= x.N.length() ? x.N : N; 
        string sign = *this < x ? "-" : "";
        int lLength = l.length();
        int rLength = r.length();
        int res = 0;
        int up = 0;
        string result = "";
        for(int i = 0; i < lLength; i++)
        {
            int sum = l[lLength - i -1] - '0' + up;
            if(i<rLength)
            {
                sum -= r[rLength - i -1] - '0';
            }
            up = sum < 0 ? -1 : 0;
            res = sum < 0 ? 10+sum : sum;
            result = to_string(res) + result;
        }
        if(up != 0){
            result = to_string(up) + result;
        }
        for(int i=0; i<result.length(); i++)
        {
            if(result[i] != '0')
            {
                return sign + result.substr(i);
            }
        }
        return "0";
    }
    string operator / (BigInt& x)
    {
        string res = N;
        BigInt i = BigInt("0");
        BigInt one = BigInt("1");
        BigInt result = *this;
        while(res[0] != '-')
        {
            result = BigInt(result-x);
            res = result.N;
            i = i + one;
        }
        return i - one;
    }
    string operator % (BigInt& x)
    {
        string res = N;
        BigInt i = BigInt("0");
        BigInt one = BigInt("1");
        BigInt result = *this;
        BigInt residue = result;
        while(res[0] != '-')
        {
            residue = result;
            result = BigInt(result-x);
            res = result.N;
            i = i + one;
        }
        return residue.N;
    }
};

int main()
{
    BigInt a = BigInt("11123123124321432142314124213423142314231431241234321431");
    BigInt b = BigInt("10214213432143214312432141");
    cout << a/b << endl;
    cout << a%b << endl;
}


