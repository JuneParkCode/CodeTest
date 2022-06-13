#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
	string input;
	cin >> input;
	sort(input.rbegin(), input.rend());
	cout << input;
}
