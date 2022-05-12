#include <iostream>
#include <string>

using namespace std;

int _map[22][22];
int info[22][22][4][3];

int dx[4] = {1, 1, 0, -1};
int dy[4] = {0, 1, 1, 1};
int r, c, winner;

void tester()
{
	for (int k = 1; k <= 2; ++k) 
		for (int x = 0; x < 4; ++x, cout << "===="<< x <<"=========\n")
			for (int i = 1; i <= 19; ++i, cout << "\n")
				for (int j = 1; j <= 19; ++j)
					cout << info[i][j][x][k];
}

int do_check(int row, int col, int direction, int user, int depth)
{
	if (info[row][col][direction][user])
		return (info[row][col][direction][user]);
	if (!_map[row][col] || _map[row][col] != user)
		return (depth - 1);
	else
	{
		info[row][col][direction][user] = do_check(row + dy[direction], col + dx[direction], direction, user, depth + 1);
		return (info[row][col][direction][user]);
	}
}

void check(int row, int col)
{
	int user;
	for (int i = 0; i < 4; ++i)
	{
		if (_map[row][col] == 0)
			continue;
		user = _map[row][col];
		info[row][col][i][user] = do_check(row, col, i, user, 1);
		if (info[row][col][i][user] == 5)
		{
			winner = _map[row][col];
			r = row;
			c = col;
			if (i == 3)
			{
				c -= 4;
				r += 4;
			}
			return ;
		}
	}
}

void solver()
{
	for (int i = 1; i <= 19; ++i)
	{
		for (int j = 1; j <= 19; ++j)
		{
			check(i, j);
			if (winner)
				return;
		}
	}
}

void getInfo()
{
	string input;

	for (int i = 1; i <= 19; ++i)
	{
		for (int j = 1; j <= 19; ++j)
		{
			cin >> input;
			_map[i][j] = stoi(input);
		}
	}
}

void printer()
{
	cout << winner << endl;
	if (winner)
		cout << r << " " << c;
}

int main(void)
{
	getInfo();
	memset(info, 0, 22 * 22 * 4 * 3 * sizeof(int));
	winner = 0;
	r = -1;
	c = -1;
	solver();
	printer();
	return (0);
}
