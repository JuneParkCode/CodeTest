#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    const int SIZE = phone_book.size();
    for(int i=0; i<SIZE-1; ++i)
    {
        string number = phone_book[i];
        string other_number = phone_book[i+1];
        if(number.size() < other_number.size() && other_number.substr(0,number.length()) == number)
        {
            return 0;
        }
    }
    return 1;
}