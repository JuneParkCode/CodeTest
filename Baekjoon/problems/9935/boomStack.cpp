#include <iostream>
#include <string>

using namespace std;

bool isBoom(const string &s, const string &word)
{
    const int S_LEN = s.length();
    const int WORD_LEN = word.length();
    int idx = S_LEN - WORD_LEN;
    if (idx < 0)
        return (false);
    else
    {
        int wIdx = 0;
        while (idx < S_LEN && s[idx] == word[wIdx])
        {
            ++idx;
            ++wIdx;
        }
        return (idx == S_LEN);
    }
}

void removeWord(string &s, const string &word, string &res)
{
    const int LEN = s.length();
    int idx = 0;
    res = "";

    while (idx < LEN)
    {
        res += s[idx];
        while (isBoom(res, word))
        {
            for (int i = 0; i < word.length(); ++i)
            {
                res.pop_back();
            }
        }
        ++idx;
    }
}

int main(void)
{
    string target;
    string answer("");
    string bombWord;
    
    cin >> target >> bombWord;
    
    int idx = 0;
    removeWord(target, bombWord, answer);
    if (answer.length() == 0)
        cout << "FRULA";
    else
        cout << answer;
}