#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[100000];
int main(void)
{
	string input;
	int numberOfCommands;
	int n;
	int sum;
	int idx;

	cin >> input;
	numberOfCommands = stoi(input);
	sum = 0;
	idx = 0;
	for (int i = 0; i < numberOfCommands; ++i)
	{
		cin >> input;
		n = stoi(input);
		if (n)
		{
			sum += n;
			arr[idx++] = n;
		}
		else
		{
			sum -= arr[--idx];
		}
	}
	cout << sum;
	return (0);
}