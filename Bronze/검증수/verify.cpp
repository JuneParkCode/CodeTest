#include <iostream>

using namespace std;

int verifyNumber(int numbers[])
{
    int sum = 0;
    for(int i=0; i<5; i++)
    {
        sum += numbers[i]*numbers[i];
    }
    return sum%10;
}

int main()
{
    int nums[5];
    
    for(int i=0; i<5; i++)
    {
        cin >> nums[i];
    } 
    cout << verifyNumber(nums);
}