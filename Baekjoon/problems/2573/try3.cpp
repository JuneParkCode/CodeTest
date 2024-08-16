#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int		arr[300][300];
bool	_marker[300][300];

void	clear(int n, int m)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			_marker[i][j] = 0;
}

void	printer(int n, int m, int _arr[][300])
{
	for (int i = 0; i < n; ++i, cout << "\n")
		for (int j = 0; j < m; ++ j, cout << " ")
			cout << _arr[i][j];
}

void	printer(int n, int m, bool _arr[][300])
{
	for (int i = 0; i < n; ++i, cout << "\n")
		for (int j = 0; j < m; ++ j, cout << " ")
			cout << _arr[i][j];
}

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
	if (arr[row][col])
		--arr[row][col];
}

// @return :  >0  -> number of island ( <= 2)
// 			   0  -> there is no island
int	checkIsland(int n, int m)
{
	int	island;

	island = 0;
	clear(n, m);
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
	//cout << "ISLAND : " <<island <<endl;
	//printer(n, m, _marker);
	return (island);
}

void	melt_island(int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (_marker[i][j])
			{
				melting(n, m, i + 1, j);
				melting(n, m, i - 1, j);
				melting(n, m, i, j + 1);
				melting(n, m, i, j - 1);
			}
		}
	}
}

int	solver(int n, int m)
{	
	int	year;
	int	flag;

	year = 0;
	while ((flag = checkIsland(n, m)) == 1)
	{
		melt_island(n, m);
		++year;
		cout << "YEAR : " << year << endl;
		printer(n, m, arr);
	}
	if (flag == 0)
		return (0);
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
	clear(n, m);
	//cout << "YEAR : 0 " <<  endl;
	//printer(n, m);
	cout << solver(n, m);
	return (0);
}
