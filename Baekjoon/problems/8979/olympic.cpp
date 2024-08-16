#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int arr[1001][4];
int nations[1001];

int cmp(int a, int b)
{
	for (int i = 1; i < 4; ++i)
	{
		if (arr[a][i] != arr[b][i])
			return (arr[a][i] > arr[b][i]);
	}
	return (arr[a][0] < arr[b][0]);
}

int cmp2(int a, int b)
{
	for (int i = 1; i < 4; ++i)
	{
		if (arr[a][i] != arr[b][i])
			return (false);
	}
	return (true);
}

int main(void)
{
	int n, m, tmp;
	cin >> n >> m;
	if (n == 1)
	{
		cout << 1;
		return (0);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		arr[tmp][0] = tmp;
		nations[i] = i + 1;
		for (int j = 1; j < 4; ++j)
		{
			cin >> arr[tmp][j];
		}
	}
	sort(nations, nations + n, cmp);

	int rank = 1;
	int i = 1;
	if (nations[0] == m)
	{
		cout << 1;
		return (0);
	}
	while (1)
	{
		if (cmp2(nations[i], nations[i - 1]) == false)
			rank = i + 1;
		if (nations[i] == m)
			break;
		++i;
	}
	cout << rank;
	return (0);
}