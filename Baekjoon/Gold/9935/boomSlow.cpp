#include <iostream>
#include <string>
#include <vector>

using namespace std;

void removeWord(string &s, const string &word)
{
    const int LEN = s.length();
    int idx = 0;
    string res("");
    while (idx < LEN)
    {
        int wIdx = 0;
        while (wIdx < word.length() && s[idx + wIdx] == word[wIdx])
        {
            ++wIdx;
        }
        if (wIdx == word.length())
        {
            idx += wIdx;
        }
        else
        {
            res += s[idx];
            ++idx;
        }
    }
    s = res;
    // cout << res << endl;
}

int main(void)
{
    string target;
    string answer("");
    string bombWord;
    
    cin >> target >> bombWord;
    
    int idx = 0;
    while (target.find(bombWord) != std::string::npos)
    {
        removeWord(target, bombWord);
    }
    if (target.length() == 0)
        cout << "FRULA";
    else
        cout << target;
}