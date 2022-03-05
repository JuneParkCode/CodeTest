#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int idx = 0;
    stack<char> st;
    const int SIZE = s.length();
    for(int i=0; i<SIZE; ++i)
    {
        if(!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    return st.empty();
}