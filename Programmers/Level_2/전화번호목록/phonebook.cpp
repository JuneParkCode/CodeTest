#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool solution(vector<string> phone_book_raw) {
    bool answer = true;
    set<string> phone_book;
    for(auto s : phone_book_raw)
    {
        phone_book.insert(s);
    }
    auto it = phone_book.begin();
    while(it!=phone_book.end())
    {
        string number = *it;
        if(++it == phone_book.end())
            return 1;
        string other_number = *it;
        if(number != other_number && other_number.substr(0,number.length()) == number)
        {
            return 0;
        }
    }
    return 1;
}