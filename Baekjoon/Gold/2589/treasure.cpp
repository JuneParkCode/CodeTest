#include <iostream>
#include <string>
#include <string.h>
#include <stack>

#define LMAX 50

using namespace std;

int w;
int h;
int mx = 0;
int info[LMAX][LMAX];
int check[LMAX][LMAX];
int _distance[LMAX][LMAX]; // 해당 지점까지의 최단 경로
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void getInput()
{
	string tmp;

	cin >> h;
	cin >> w;
	for (int i = 0; i < h; ++i)
	{
		cin >> tmp;
		for (int j = 0; j < w; ++j)
		{
			info[i][j] = tmp[j] == 'W' ? 0 : 1;
		}
	}
}

int track(const int row, const int col, const int dist, int &_mx)
{
	if (row < 0 || col < 0 || row >= h || col >= w || check[row][col] || !info[row][col])
		return (0);
	if (_distance[row][col] && dist > _distance[row][col])
		return (0);
	int dupChecker = 0;
	for (int dir = 0; dir < 4; ++dir)
	{
		dupChecker += (check[row + dy[dir]][col + dx[dir]]);
		if (dupChecker > 1)
		{
			return (0);
		}
	}
	int distArr[4];
	int res = 0;
	check[row][col] = true;
	if (!_distance[row][col] || dist < _distance[row][col])
	{
		_distance[row][col] = dist;
	}
	for (int dir = 0; dir < 4; ++dir)
	{
		track(row + dy[dir], col + dx[dir], dist + 1, _mx);
	}
	check[row][col] = false;
	return (res);
}

int getMax()
{
	int res = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			res = res < _distance[i][j] ? _distance[i][j] : res;
		}
	}
	return (res);
}

void solver()
{
	int res;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			res = 0;
			memset(_distance, 0, sizeof(_distance));
			track(i, j, 0, res);
			res = getMax();
			mx = mx < res ? res : mx;
		}
	}
}

int main(void)
{
	getInput();
	memset(check, 0, sizeof(check));
	solver();
	cout << mx;
}