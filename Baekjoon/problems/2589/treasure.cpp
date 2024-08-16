#include <iostream>
#include <string>
#include <string.h>
#include <queue>

#define LMAX 50

using namespace std;

int w;
int h;
string info[LMAX];

int check[LMAX][LMAX];
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
		info[i] = tmp;
	}
}

int track(int row, int col)
{
	if (info[row][col] == 'W')
		return 0;
	queue<pair<int, int> > posQ;
	int max = 1;
	memset(check, 0, sizeof(check));
	pair<int ,int> p (row, col);
	posQ.push(p);
	check[row][col] = 1;
	while (!posQ.empty())
	{
		p = posQ.front();
		posQ.pop();
		row = p.first;
		col = p.second;
		for (int dir = 0 ; dir < 4; ++dir)
		{
			int nextRow = row + dy[dir];
			int nextCol = col + dx[dir];
			// boundary
			if (nextRow < 0 || nextCol < 0 ||
				nextRow >= h || nextCol >= w ||
				info[nextRow][nextCol] == 'W' ||
				check[nextRow][nextCol] != 0)
				continue ;
			check[nextRow][nextCol] = check[row][col] + 1;
			max = max < check[nextRow][nextCol] ? check[nextRow][nextCol] : max;
			pair<int, int> t(nextRow, nextCol);
			posQ.push(t);
		}
	}
	return (max - 1);
}

int solver()
{
	int res = 0;
	int max = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			res = track(i, j);
			max = max < res ? res : max;
		}
	}
	return (max);
}

int main(void)
{
	getInput();
	cout << solver();
}