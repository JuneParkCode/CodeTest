#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>

using namespace std;

set<int> n1;
set<int> n2;
vector<int> v1;
map<int, int> mp1;

int main(void)
{
	string input;
	int n, m;
	int x;

	cin >> input;
	n = stoi(input);
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		x = stoi(input);
		n1.insert(x);
	}
	cin >> input;
	m = stoi(input);
	for (int i = 0; i < m; ++i)
	{
		cin >> input;
		x = stoi(input);
		n2.insert(x);
		v1.push_back(x);
	}
	set<int>::iterator x1 = n1.begin();
	set<int>::iterator x2 = n2.begin();
	do
	{
		if (*x1 == *x2)
		{
			mp1[*x1] = 1;
			x1++;
			x2++;
		}
		else if (*x1 < *x2)
		{
			x1++;
		}
		else
		{
			mp1[*x2] = 0;
			x2++;
		}
	} while (x1 != n1.end() && x2 != n2.end());
	for (auto x : v1)
	{
		cout << mp1[x] << " ";
	}
	return (0);
}