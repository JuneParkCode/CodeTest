#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

int	arr[4000];

int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	int result = 0;
	for (int i = 0; i < s2.length(); ++i)
		arr[i] = 1;
	if (s1.length() < s2.length())
	{
		string tmp;
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	for (int idx_s2 = 0; (idx_s2 < s2.length()) && (arr[idx_s2] + idx_s2 < s2.length()); ++idx_s2)
	{
		string findStr = s2.substr(idx_s2, arr[idx_s2]);
		int idx_s1 = s1.find(findStr);
		int max = 0;
		while (idx_s1 != string::npos)
		{
			int add = arr[idx_s2];
			while ((idx_s1 + add) < s1.length() && (idx_s2 +  add) < s2.length() && s1[idx_s1 + add] == s2[idx_s2 + add])
				++add;
			max = max < add ? add : max;
			idx_s1 = s1.find(findStr, idx_s1 + 1);
		}
		int t = 0;
		for (int x = max; (max >= 0 && (idx_s2 + t) < s2.length()); --max)
			arr[idx_s2 + t++] = max;
		result = arr[idx_s2] > result ? arr[idx_s2] : result;
	}
	cout << result;
	return (0);
}
