#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


string make_pattern(string current, string pattern)
{
    int     len_str;

    len_str = current.size();
    if (pattern.compare("") == 0)
        return (current);
    for (int i = 0; i < len_str; ++i)
    {
        if (current[i] != pattern[i] && pattern[i] != '?')
            pattern[i] = '?';
    }
    return (pattern);
}

int main(void)
{
    string  current;
    string  pattern;
    int     n;

    // input first line
    cin >> current;
    n = atoi(current.c_str());
    // input second line
    cin >> current;
    pattern = current;
    // input n-th line
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> current;
        pattern = make_pattern(current, pattern);
    }
    cout << pattern;
    return (0);
}