#include <iostream>
#include <string>

using namespace std;
int main(void)
{
    string  input;
    int     n;
    int     current_number;
    int     right_digit;
    int     sum;
    int     cycle;

    cin >> input;
    n = stoi(input);
    current_number = n;
    cycle = 0;
    do
    {
        right_digit = current_number % 10;
        if (current_number < 10)
            current_number *= 10;
        sum = current_number / 10 + current_number % 10;
        current_number = right_digit * 10 + sum % 10;
        cycle++;
    } while (n != current_number);
    cout << cycle;
    return (0);
}