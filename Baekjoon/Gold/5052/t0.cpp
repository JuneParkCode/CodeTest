#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getNumberFromUser()
{
    int n;
    cin >> n;
    return (n);
}

vector<string> getPhoneBook(const int NUM_STRINGS)
{
    vector<string> phoneBookVector;
    for (int n = 0; n < NUM_STRINGS; ++n)
    {
        string phoneNumber;
        cin >> phoneNumber;
        phoneBookVector.push_back(phoneNumber);
    }
    return (phoneBookVector);
}

bool isCallablePhoneBook(vector<string> &phoneBookVector, const int NUM_STRINGS)
{
    const int VECTOR_SIZE = phoneBookVector.size();
    sort(phoneBookVector.begin(), phoneBookVector.end());
    for (int suffixIdx = 0; suffixIdx < VECTOR_SIZE - 1; ++suffixIdx)
    {
        const string &suffix = phoneBookVector[suffixIdx];
        const int LEN_SUFFIX = suffix.length();
        const string &targetStr = phoneBookVector[suffixIdx + 1];
        if (LEN_SUFFIX == targetStr.length())
            continue ;
        if (targetStr.compare(0, LEN_SUFFIX, suffix) == 0)
            return (false);
    }
    return (true);
}

void printIsCallable(const bool isCallable)
{
    if (isCallable)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

void solver(const int TC_NUMS)
{
    for (int tc = 0; tc < TC_NUMS; ++tc)
    {
        const int NUM_STRINGS = getNumberFromUser();
        vector<string> phoneBookVector = getPhoneBook(NUM_STRINGS);
        bool isCallable = isCallablePhoneBook(phoneBookVector, NUM_STRINGS);
        printIsCallable(isCallable);
    }
}

int main(void)
{
    const int TC_NUMS = getNumberFromUser();
    solver(TC_NUMS);
}