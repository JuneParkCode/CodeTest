#include <iostream>
#include <string>
#define MAX_SIZE_N 1000000
#define MAX_SIZE_M 10000
#define MAX_SIZE_K 10000
#define DIV_NUM 1000000007

#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
/*
 * Problem:
 * 어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 곱을 구하려 한다. 
 * Example: 
 * 만약에 1, 2, 3, 4, 5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 곱을 구하라고 한다면 240을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 곱을 구하라고 한다면 48이 될 것이다.
 * N(1 ≤ N ≤ 1,000,000) 수의 개수
 * M(1 ≤ M ≤ 10,000) 수의 변경이 일어나는 횟수
 * K(1 ≤ K ≤ 10,000) 구간의 곱을 구하는 횟수
 */

void	get_nmk(int *n, int *m, int *k)
{
	string input;
	// get n
	cin >> input;
	*n = stoi(input);
	// get m
	cin >> input;
	*m = stoi(input);
	// get k
	cin >> input;
	*k = stoi(input);
}

void	get_ns(int *arr_n, const int N)
{
	int		idx_arr;
	string	input;

	idx_arr = 0;
	while (idx_arr < N)
	{
		cin >> input;
		arr_n[idx_arr] = stoi(input);
		++idx_arr;
	}
}

void	get_commands(int arr_commands[][3], const int M, const int K)
{
	int		idx_arr;
	string	input;

	idx_arr = 0;
	while (idx_arr < (M + K))
	{
		for (int i = 0; i < 3; ++i)
		{
			cin >> input;
			arr_commands[idx_arr][i] = stoi(input);
		}
		++idx_arr;
	}
}

void get_mult(int *arr_n, int a, int b)
{
	size_t	res;
	int		A, B;

	res = 1;
	A = a < b? a - 1 : b - 1;
	B = a < b? b : a;
	for (int idx_arr = A; idx_arr < B; ++idx_arr)
	{
		res = (res * arr_n[idx_arr]) % DIV_NUM;
		if (res == 0)
			break ;
	}
	cout << res << "\n";
}

void	replace(int *a, int b)
{
	*a = b;
}

size_t solver(int *arr_n, int arr_commands[][3], const int M, const int K)
{
	size_t	mults;

	mults = 1;
	for (int idx_commands = 0; idx_commands < (M + K); ++idx_commands)
	{
		const int	command = arr_commands[idx_commands][0];
		const int	a = arr_commands[idx_commands][1];
		const int	b = arr_commands[idx_commands][2];
		
		if (command == 1)
		{
			replace(&arr_n[a - 1], b);
		}
		else if (command == 2)
		{
			get_mult(arr_n, a, b);
		}
	}
	return (mults);
}

int	main(void)
{
	int n, m, k;
	int	arr_n[MAX_SIZE_N];
	int	arr_commands[MAX_SIZE_M + MAX_SIZE_K][3];

	fastio;
	get_nmk(&n, &m, &k);
	get_ns(arr_n, n);
	get_commands(arr_commands, m, k);
	solver(arr_n, arr_commands, m, k);
	return (0);
}
