#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void getInput(int &numberOfStrings, vector<string> &strVector);
bool solver(const string &str);

int main(void)
{
	int numberOfStrings;
	vector<string> strVector;

	getInput(numberOfStrings, strVector);
	for (int testCase = 0; testCase < numberOfStrings; ++testCase)
	{
		if(solver(strVector[testCase]))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}

void getInput(int &numberOfStrings, vector<string> &strVector)
{
	cin >> numberOfStrings;
	for (int n = 0; n < numberOfStrings; ++n)
	{
		string s;
		cin >> s;
		strVector.push_back(s);
	}
}

bool solver(const string &str)
{
	stack<char> bracketStack;

	for (char c : str)
	{
		if (c == '(')
		{
			bracketStack.push('(');
		}
		else
		{
			if (bracketStack.empty())
				return (false);
			bracketStack.pop();
		}
	}
	return (bracketStack.empty());
}
