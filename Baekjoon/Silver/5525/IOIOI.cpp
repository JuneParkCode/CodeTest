#include <iostream>
#include <string>

using namespace std;

const char IO[] = {'I', 'O'};

int findPn(const string targetString, const int n, const int pos)
{
	const int LEN_STRING = targetString.length();
	int start = pos;
	while ((start + n) <= LEN_STRING)
	{
		const int P_STR_LEN = 2 * n + 1;
		int i = 0;
		int findIdx = start + i;
		while (i < P_STR_LEN && targetString[findIdx] == IO[i % 2])
		{
			findIdx++;
			i++;
		}
		if (i == P_STR_LEN)
			return (start);
		++start;
	}
	return (-1);
}

void getInput(int &n, int &m, string &s)
{
	cin >> n >> m >> s;
}

int getSequenceNumbers(const string s, const int pos)
{
	int idx = pos;
	int i = 1;
	while (idx < s.length() && s[idx] == IO[i % 2])
	{
		++i;
		++idx;
	}
	return ((i - 1) / 2);
}

void solver(const int n, const string s)
{
	int result = 0;
	const int P_STR_LEN = 2 * n + 1;
	int i = 0;
	while (i < (s.length() - n))
	{
		const int foundIdx = findPn(s, n, i);
		if (foundIdx != -1)
		{
			const int seqNum = getSequenceNumbers(s, foundIdx + P_STR_LEN);
			result += 1 + seqNum;
			i = foundIdx + P_STR_LEN + (seqNum * 2);
		}
		else
		{
			++i;
		}

	}
	cout << result;
}

int main(void)
{
	int n, m;
	string s;
	getInput(n, m ,s);
	solver(n, s);
}
