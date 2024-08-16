#include <iostream>
#include <string>
#include <map>

using namespace std;

string palindromify(string &name)
{
    const int LEN = name.length();
    map<char, int> cMap;
    map<char, int> evenMap;
    map<char, int> oddMap;

    for (char &c : name)
    {
        cMap[c] += 1;
    }
    int odd = 0;
    for (auto &p : cMap)
    {
        if (p.second & 1)
        {
            odd++;
            if (odd > 1)
                return ("I'm Sorry Hansoo");
            oddMap[p.first] = 1;
            evenMap[p.first] = p.second - 1;
        }
        else
        {
            evenMap[p.first] = p.second;
        }
    }
    char str[LEN + 1];
    int i = 0;
    for (auto &p : evenMap)
    {
        for (int j = 0; j < p.second; j += 2)
        {
            str[i] = p.first;
            str[LEN - i - 1] = p.first;
            ++i;
        }
    }
    for (auto &p : oddMap)
    {

        str[i] = p.first;
    }
    str[LEN] = 0;
    return (str);
}

int main(void)
{
    string name;
    cin >> name;
    cout << palindromify(name);
}