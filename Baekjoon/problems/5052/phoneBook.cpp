#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator()(const string &lhs, const string &rhs) const
    {
        // cout << "\n" << lhs <<  ":" << rhs <<endl;
        if (lhs.length() < rhs.length())
        {
            // cout << lhs.compare(0, lhs.length(), rhs, 0, lhs.length());
            return (lhs.compare(0, lhs.length(), rhs, 0, lhs.length()));
        }
        else
        {
            // cout << rhs.compare(0, rhs.length(), lhs, 0, rhs.length());
            return (rhs.compare(0, rhs.length(), lhs, 0, rhs.length()));
        }
    }
}; 


// struct cmp
// {
//     bool operator()(const string &lhs, const string &rhs) const
//     {
//         if (lhs.length() != rhs.length())
//         {
//             return (lhs.length() < rhs.length());
//         }
//         else
//         {
//             return (lhs < rhs);
//         }
//     }
// }; 

int getNumberFromUser()
{
    int n;
    cin >> n;
    // scanf("%d", &n);
    return (n);
}

void getPhoneBook(set<string, cmp> &phoneBook, const int NUM_STRINGS)
{
    phoneBook.insert("----");
    for (int n = 0; n < NUM_STRINGS; ++n)
    {
        // char phoneNumber[11];
        // scanf("%s", phoneNumber);
        string phoneNumber;
        cin >> phoneNumber;
        // cout << "\nNUM : " <<phoneNumber;
        phoneBook.insert(phoneNumber);
        // for (auto &s : phoneBook)
        // {
        //     cout << s << endl;
        // }
        // cout << "===\n";
    }
}

bool isCallablePhoneBook(set<string, cmp> &phoneBook, const int NUM_STRINGS)
{
    return (phoneBook.size() == NUM_STRINGS + 1);
}

void printIsCallable(const bool isCallable)
{
    if (isCallable)
    {
        cout << "YES\n";
        // printf("YES\n");
    }
    else
    {
        cout << "NO\n";
        // printf("NO\n");
    }
}

void solver(vector<bool> &ans, const int TC_NUMS)
{
    for (int tc = 0; tc < TC_NUMS; ++tc)
    {
        const int NUM_STRINGS = getNumberFromUser();
        set<string, cmp> phoneBook;
        getPhoneBook(phoneBook, NUM_STRINGS);
        bool isCallable = isCallablePhoneBook(phoneBook, NUM_STRINGS);
        ans.push_back(isCallable);
    }
}

int main(void)
{
    const int TC_NUMS = getNumberFromUser();
    vector<bool> ans;
    solver(ans, TC_NUMS);
    for (const bool &x : ans)
    {
        printIsCallable(x);
    }
}