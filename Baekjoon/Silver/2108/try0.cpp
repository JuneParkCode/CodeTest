#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

int	myRound(double n)
{
	return ((n - floor(n)) < (ceil(n) - n)) ? floor(n) : ceil(n);
}

int	cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second > b.second);
}

int	main(void)
{
	string		input;
	int			n;
	int			min, max;
	long long	sum;

	cin >> input;
	n = stoi(input);

	vector<int>	v (n);
	map<int, int> m;
	
	min = INT_MAX;
	max = INT_MIN;
	sum = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		v[i] = stoi(input);
		min = min > v[i] ? v[i] : min;
		max = max < v[i] ? v[i] : max;
		sum += v[i];
		++m[v[i]];
	}
	int		ave;
	int		mid;
	int		mode;
	int		_range;
	
	sort(v.begin(), v.end());
	vector<pair<int, int> > tmp(m.begin(), m.end());
	sort(tmp.begin(), tmp.end(), cmp);
	
	if (tmp[0].second == tmp[1].second)
		mode = tmp[1].first;
	else
		mode = tmp[0].first;
	
	ave = myRound((sum / (double)n));
	mid = v[n / 2];
	_range = max - min;

	cout << ave << endl;
	cout << mid << endl;
	cout << mode << endl;
	cout << _range <<endl;
	return (0);
}
