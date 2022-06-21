#include <set>
#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    int result = 0;
    cin >> n >> m;
    
    set<string> sets;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        sets.insert(s);
    }
    for (int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        result += (sets.find(s) != sets.end());
    }
    cout << result;
}