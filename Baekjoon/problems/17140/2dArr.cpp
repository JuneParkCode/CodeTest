#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
	TESTS
	1 2 2
	1 2 1
	2 1 3
	3 3 3

	1 2 1
	1 2 1
	2 1 3
	3 3 3

	1 2 3
	1 2 1
	2 1 3
	3 3 3

	1 2 4
	1 2 1
	2 1 3
	3 3 3

	1 2 5
	1 2 1
	2 1 3
	3 3 3

	3 3 3
	1 1 1
	1 1 1
	1 1 1
*/

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second != b.second)
		return (a.second < b.second);
	else
		return (a.first < b.first);
}


void getInput(int &r, int &c, int &k, vector<vector<int> > &v)
{
	cin >> r;
	cin >> c;
	cin >> k;
	for (int i = 0; i < 3; ++i)
	{
		v.push_back(vector<int> ());
		for (int j = 0; j < 3; ++j)
		{
			v[i].push_back(0);
			cin >> v[i][j];
		}
	}
}

void f_R(vector<vector<int>  > &v)
{
	int max = 3;
	for (vector<int> &_v : v)
	{
		map<int, int> m;
		for (int n : _v)
		{
			if (n == 0)
				continue;
			m[n]++;
		}


		_v.clear();
		vector<pair<int, int> > sorted;
		for (auto &it :m)
		{
			sorted.push_back(it);
		}
		sort(sorted.begin(), sorted.end(), cmp);

		auto it = sorted.begin();
		while (it != sorted.end() && _v.size() <= 100)
		{
			_v.push_back((*it).first);
			_v.push_back((*it).second);
			++it;
		}
		max = max < _v.size() ? _v.size() : max;
	}
	for (vector<int> &_v : v)
	{
		while (_v.size() != max)
		{
			_v.push_back(0);
		}
	}
}

void f_C(vector<vector<int> > &v)
{
	const int SIZE = v.size();
	int max = 3;
	int	col = 0;

	while (col < v[0].size())
	{
		map<int, int> m;
		for (int row = 0; row < SIZE; ++row)
		{
			if (v[row][col] == 0)
				continue;
			m[v[row][col]]++;
		}

		int	idx = 0;

		vector<pair<int, int> > sorted;
		for (auto &it :m)
		{
			sorted.push_back(it);
		}
		sort(sorted.begin(), sorted.end(), cmp);

		vector<int> _v;
		auto it = sorted.begin();
		while (it != sorted.end() && _v.size() <= 100)
		{
			_v.push_back((*it).first);
			_v.push_back((*it).second);
			++it;
		}
		max = max < _v.size() ? _v.size() : max;
		++idx;

		int row = 0;
		while (v.size() < _v.size())
		{
			v.push_back(vector<int> (v[0].size(), 0));
		}
		while (row < v.size())
		{
			int n = _v[row];
			if (row >= _v.size())
				n = 0;
			v[row++][col] = n;
		}
		++col;
	}
}

void printV(vector<vector<int> > &v)
{
	for (auto &_v : v)
	{
		for (auto &n : _v)
		{
			cout << n << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(void)
{
	vector<vector<int> > v;

	int r, c, k;
	int tries = 0;
	getInput(r, c, k ,v);
	while ((v.size() < r  || v[0].size() < c || v[r - 1][c - 1] != k) && tries <= 100)
	{
		if (v.size() >= v[0].size())
		{
			// cout << tries + 1 << " : R\n";
			f_R(v);
		}
		else
		{
			// cout << tries + 1 << " : C\n";
			f_C(v);
		}
		// printV(v);
		++tries;
	}
	if (tries > 100)
		cout << -1;
	else
		cout << tries;
}
