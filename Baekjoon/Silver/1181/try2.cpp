#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator()(const string &a, const string &b) const
	{
		if (a.length() != b.length())
			return (a.length() < b.length());
		else
			return (a < b);
	}
};

int main(void)
{

	set<string, cmp> inputs;
	int numberOfInputs;
	string input;

	cin >> numberOfInputs;
	for (int i = 0; i < numberOfInputs; ++i)
	{
		cin >> input;
		inputs.insert(input);
	}
	for (auto &str : inputs)
	{
		cout << str << endl;
	}
}
