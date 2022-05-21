#include <iostream>
#include <map>

using namespace std;

map<int, bool> nums;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	int x;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		nums[x] = true;
	}
	cin >> m;
	for (int i = 0; i < m; ++i, cout << " ")
	{
		cin >> x;
		cout << nums[x];
	}
	return (0);
}