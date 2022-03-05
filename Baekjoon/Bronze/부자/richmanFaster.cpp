#include <iostream>
#include <string>
#include <vector>
#define DIG 3
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
        // 18개
        vector<long long> lSet;
        vector<long long> rSet;
        vector<long long> resSet;

        const string l = N.length() >= x.N.length() ? N : x.N;
        const string r =  N.length() >= x.N.length() ? x.N : N;

        const int lLength = l.length();
        const int rLength = r.length();

        for(int i=0; i<lLength; i += DIG)
        {
            lSet.push_back(stoll(l.substr(i,DIG)));
        }

        for(int i=0; i<rLength; i += DIG)
        {
            rSet.push_back(stoll(r.substr(i,DIG)));
        }
        
        for(int i=0; i<lSet.size(); i++)
        {
            int up = 0;
            if(i<rSet.size())
            {
                long long sum = lSet[lSet.size() - i - 1] + rSet[rSet.size() - i - 1] + up;
                cout<<sum<<endl;
                up = sum / 1E3;
                resSet.push_back(sum - up * 1E3);
            }
            else
            {
                long long sum = lSet[lSet.size() - i - 1] + up;
                cout<<sum<<endl;
                up = sum / 1E3;
                resSet.push_back(sum - up * 1E3);
            }
        }

        string result = "";
        for(int i=0; i< resSet.size(); i++)
        {
            result += to_string(resSet[i]);
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
    BigInt a = BigInt("1111111");
    BigInt b = BigInt("9999");
    cout << a+b << endl;
    cout << 1111111 + 9999;
}


