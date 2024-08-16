#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
	vector<int> t;
	t.reserve(100);
	for (auto& n : t)
	{
		cout << n;
	}
}
