#include <iostream>
#include <string>

using namespace std;

const char IO[] = {'I', 'O'};
void getInput(int &n, int &m, string &s)
{
	cin >> n >> m >> s;
}

void solver(const int n, const string s)
{
	int result = 0;
	const int P_STR_LEN = 2 * n + 1;
	int i = 0;
	while (i < (s.length() - n))
	{
		int t = 0;
		while (s[i + t] == IO[t % 2])
		{
			++t;
		}
		if (t >= P_STR_LEN)
		{
			result += 1 + (t - P_STR_LEN) / 2;
		}
		i += t ? t: 1;
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
