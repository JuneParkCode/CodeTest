#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <algorithm>

#define N_MAX 10000
#define K_MAX 1000
#define POS_MAX 1000000

using namespace std;

int solver(set<int> &pos, const int numberOfCentral)
{
	int posSize = pos.size();
	int min, max;
	int bias = numberOfCentral - 1;
	int length;

	if (posSize <= numberOfCentral)
	{
		return (0);
	}

	vector<int> v;
	for (auto tmp : pos)
		v.push_back(tmp);

	min = v[0];
	max = v[posSize - 1];
	length = max - min;
	vector<int> d;
	for (int i = 0; i < posSize - 1; ++i)
		d.push_back(v[i + 1] - v[i]);
	sort(d.begin(), d.end());
	int sub = 0;
	auto it = d.end();
	for (int i = 0; i < bias && it != d.begin(); ++i)
	{
		sub += *(--it);
	}
	return (length - sub);
}

int main(void)
{
	int tmp;
	int numberOfSensor, numberOfCentral;
	set<int> pos;

	cin >> numberOfSensor;
	cin >> numberOfCentral;
	for (int i = 0; i < numberOfSensor; ++i)
	{
		cin >> tmp;
		pos.insert(tmp);
	}
	cout << solver(pos, numberOfCentral);
	return (0);
}