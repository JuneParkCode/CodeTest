#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int		arr[300][300];
bool	_marker[300][300];

void	marking(int n, int m, int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col >= m)
		return ;
	if (arr[row][col] && !_marker[row][col])
	{
		_marker[row][col] = 1;
		marking(n, m, row + 1, col);
		marking(n, m, row - 1, col);
		marking(n, m, row, col + 1);
		marking(n, m, row, col - 1);
	}
}
void	melting(int n, int m, int row, int col)
{
	if (row < 0 || row >= n || col < 0 || col >= m)
		return ;
	if (arr[row][col] && _marker[row][col])
	{
		_marker[row][col] = 0;
		--arr[row][col];
		marking(n, m, row + 1, col);
		marking(n, m, row - 1, col);
		marking(n, m, row, col + 1);
		marking(n, m, row, col - 1);
	}
}

// @return :  >0  -> number of island ( <= 2)

// @return :  >0  -> number of island ( <= 2)
// 			   0  -> there is no island
int	checkIsland(int n, int m)
{
	int	island;;

	island = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j] && !_marker[i][j])
			{
				marking(n, m, i, j);
				if (++island == 2)
					return (island);
			}
		}
	}
	return (island);
}

void	melt_island(int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (arr[i][j])
			{
				melting(n, m, i, j);
				return ;
			}
		}
	}
}

int	solver(int n, int m)
{	
	int	year;

	year = 0;
	while (checkIsland(n, m) == 1)
	{
		melt_island(n, m);
		++year;
		memset(_marker, 0, n * m * sizeof(bool));
	}
	return (year);
}

void	getInput(int &n, int &m)
{
	string input;

	cin >> input;
	n = stoi(input);
	cin >> input;;
	m = stoi(input);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> input;
			arr[i][j] = stoi(input);
		}
	}
}

int	main(void)
{
	int n, m;

	getInput(n, m);
	memset(_marker, 0, n * m * sizeof(bool));
	cout << solver(n, m);
	return (0);
}
