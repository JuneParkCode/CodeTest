#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct
{
	bool operator()(const string &a, const string &b) const
	{
		if (a.length() != b.length())
			return (a.length() < b.length());
		else
			return (a < b);
	}
}cmp;

void solver();
void getInput(vector<string> &inputs);
void print(vector<string> &inputs);

int main(void)
{
	solver();
	return (0);
}

void solver()
{
	vector<string> inputs;
	getInput(inputs);
	sort(inputs.begin(), inputs.end(), cmp);
	print(inputs);
}

void getInput(vector<string> &inputs)
{
	int numberOfInputs;
	string inputStr;

	cin >> numberOfInputs;
	for (int input = 0; input < numberOfInputs; ++input)
	{
		cin >> inputStr;
		inputs.push_back(inputStr);
	}
}

void print(vector<string> &inputs)
{
	string prev = "";
	for (string &str : inputs)
	{
		if (prev != str)
			cout << str << endl;
		prev = str;
	}
}
