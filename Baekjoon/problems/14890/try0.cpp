#include <iostream>
#include <string>

using namespace std;

int	N;
int	MAP[100][100];
int	S_MAP[100][100];
int	L;

void	get_input()
{
	string	input;
	// get N
	cin >> input;
	N = stoi(input);
	// get L
	cin >> input;
	L = stoi(input);
	// get MAP
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cin >> input;
			MAP[r][c] = stoi(input);
			S_MAP[r][c] = 0;
		}
	}
}

int	row_checker()
{
	int		res = 0;
	int		height;
	int		dh;
	bool	checker;
	int		S_MAP[100][100];
	bzero(S_MAP, sizeof(int) * (100 * 100));
	// forward
	for (int r = 0; r < N; ++r)
	{
		height = MAP[r][0];
		checker = true;
		for (int c = 1; c < N && checker; ++c)
		{
			dh = MAP[r][c] - height;
			if (dh == 0)
				continue;
			else if ((dh == 1 || dh == -1) && !S_MAP[r][c])
			{
				int	slope = L;
				while (c < N && slope && !S_MAP[r][c])
				{
					S_MAP[r][c] = dh;
					--slope;
					++c;
				}
				if (slope)
					checker = false;
				else
					height += dh;
			}
			else
				checker = false;
		}
		res += checker;
	}
	// backward
	for (int r = N - 1; r >= 0; ++r)
	{
		height = MAP[r][N - 1];
		for (int c = N - 2; c >= 0; --c)
		{
			dh = MAP[r][c] - height;
			if (dh == 0)
				continue;
			else if ((dh == 1 || dh == -1) && !S_MAP[r][c])
			{
				int	slope = L;
				while (c >= 0 && slope && !S_MAP[r][c])
				{
					S_MAP[r][c] = dh;
					--slope;
					--c;
				}
				if (slope)
					checker = false;
				else
					height += dh;
			}
			else
				checker = false;
			res += checker;
		}
	}
	return (res);
}

int	col_checker()
{
	int		res = 0;
	int		height;
	int		dh;
	bool	checker;
	int		S_MAP[100][100];
	bzero(S_MAP, sizeof(int) * (100 * 100));
	// forward
	for (int c = 0; c < N; ++c)
	{
		height = MAP[0][c];
		checker = true;
		for (int r = 1; r < N && checker; ++r)
		{
			dh = MAP[r][c] - height;
			if (dh == 0)
				continue;
			else if ((dh == 1 || dh == -1) && !S_MAP[r][c])
			{
				int	slope = L;
				while (r < N && slope && !S_MAP[r][c])
				{
					S_MAP[r][c] = dh;
					--slope;
					++r;
				}
				if (slope)
					checker = false;
				else
					height += dh;
			}
			else
				checker = false;
		}
		res += checker;
	}
	// backward
	for (int c = N - 1; c >= 0; ++c)
	{
		height = MAP[N - 1][c];
		for (int r = N - 2; r >= 0; --r)
		{
			dh = MAP[r][c] - height;
			if (dh == 0)
				continue;
			else if ((dh == 1 || dh == -1) && !S_MAP[r][c])
			{
				int	slope = L;
				while (r >= 0 && slope && !S_MAP[r][c])
				{
					S_MAP[r][c] = dh;
					--slope;
					--r;
				}
				if (slope)
					checker = false;
				else
					height += dh;
			}
			else
				checker = false;
			res += checker;
		}
	}
	return (res);;
}

int	solver()
{
	return (row_checker() + col_checker());
}

int	main(void)
{
	int	res;

	res = 0;
	get_input();
	res = solver();
	cout << res;
}
