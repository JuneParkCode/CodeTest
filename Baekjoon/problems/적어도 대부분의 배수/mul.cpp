#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
    int x = a >= b ? a : b;
    int y = a >= b ? b : a;
    int r = x % y;
    if (r == 0)
        return (y);
    else
        return (gcd(y, r));
}

int main(void)
{
    string  input;
    vector<int> nums;
    vector<int>::iterator iter;
    for (int i = 0; i < 5; ++i)
    {
        cin >> input;
        nums.push_back(stoi(input));
    }
    int a,b,c;
    int res;
    int min = 1000000000;
    for (int i = 0; i < 3; ++i)
    {
        a = nums[i];
        for (int j = i + 1; j < 4; ++j)
        {
            b = nums[j];
            for (int k = j + 1 ; k < 5; ++k)
            {
                c = nums[k];
                res = a * b * c / gcd(a, b) / gcd(c, a * b / gcd(a,b));
                min = min > res ? res : min;
            }
        }
    }
    cout << min;
}