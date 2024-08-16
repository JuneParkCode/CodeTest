#include <iostream>
#include <stdio.h>

using namespace std;

int arr[10000];

int main(void)
{
	int n;
	for (int i = 1; i < 10000; ++i)
	{
		int tmp = i;
		int x = i;
		while (tmp)
		{
			x += tmp % 10;
			tmp /= 10;
		}
		if (x < 10000)
			arr[x] = 1;
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return (0);
}
