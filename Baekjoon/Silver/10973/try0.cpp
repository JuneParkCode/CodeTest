#include <iostream>
#include <string>

#define SWAP(a, b, tmp) (tmp = a, a = b, b = tmp)

using namespace std;

int arr[10000];
int arr2[10000];

int checker(const int &n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] != i + 1)
			return (false);
	}
	return (true);
}

void swap(const int &n, int curPos)
{
	int limit;
	int res;
	int tmp;

	limit = arr[curPos];
	res = curPos + 1;
	for (int i = curPos + 1; i < n; ++i)
	{
		res = ((arr[i] > arr[res] && arr[i] < limit) ? i : res);
	}
	SWAP(arr[curPos], arr[res], tmp);
}

int solver(const int &n)
{
	if (checker(n))
		return (-1);
	for (int i = n - 1; i > 0; --i)
	{
		if (arr[i - 1] > arr[i])
		{
			swap(n, i - 1);
			for (int j = 0; j < i; ++j)
			{
				arr2[arr[j] - 1] = 1;
			}
			int j = n - 1;
			for (int k = 0; k < n && j >= i; ++k)
			{
				if (!arr2[k])
					arr[j--] = k + 1;
			}
			return (0);
		}
	}
	return (0);
}

void getInput(int &n)
{
	string input;

	cin >> input;
	n = stoi(input);
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		arr[i] = stoi(input);
		arr2[i] = 0;
	}
}

void printer(const int &n)
{
	for (int i = 0; i < n; ++i, cout << " ")
	{
		cout << arr[i];
	}
}

int main(void)
{
	int n;

	getInput(n);
	if (solver(n) == -1)
		cout << "-1";
	else
		printer(n);
	return (0);
}