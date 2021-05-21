#include <string>
#include <vector>
#include <iostream>

using namespace std;
int compString(string a, string b)
{
    int length = a.length();
    for(int idx=0; idx<length; ++idx)
    {
        if(a[idx] > b[idx]) return 1;
        else if(a[idx] < b[idx]) return -1;
    }
    return 0;
}
int findStr(const string s,const string t,int comp=-1)
{
    int sLength = s.length();
    int tLength = t.length();
    for(int idx=0; idx<sLength-tLength+1; ++idx)
    {
        string compS="";
        for(int i=0; i<tLength; ++i)
        {
            compS += s[idx+i];
        }
        if(compS == t && comp<idx)
        {
            return idx;
        }
    }
    return -1;
}
vector<string> solution(vector<string> strings) 
{
    vector<string> answer;
    const string T1  = "110";
    const string T2  = "111";
    int idxT1,idxT2;
    for(auto s : strings)
    {
        string res = "";
        idxT2 = s.find(T2);
        idxT1 = s.find(T1,idxT2);
        while(idxT1 != -1 && idxT2 != -1)
        {
            string newS = s.substr(0,idxT1) + s.substr(idxT1+T1.length());
            res = res + newS.substr(0,idxT2) + T1 ;
            s =  newS.substr(idxT2);
            
            idxT2 = s.find(T2); 
            idxT1 = s.find(T1,idxT2);
        }
        answer.push_back(res+s);
    }
    return answer;
}