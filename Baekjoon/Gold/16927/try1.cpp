#include <string>
#include <iostream>

using namespace std;

// n, m <= 300

int	arr[300 * 300];

void	solver(int n, int m, const int r, int *origin_arr, int *res_arr)
{
	int	depth = 0;

	while (n >= 2 && m >= 2)
	{
		int	ARR_SIZE = 2 * (n + m) - 4;
		int	ROTATION = r % ARR_SIZE;
		int	tmp_res[ARR_SIZE];
		int	tmp_idx = ARR_SIZE - ROTATION;

		// copy as 1-dimension ARR
		for (int col = 0; col < m; ++col)
			tmp_res[tmp_idx++ % ARR_SIZE] = origin_arr[col];
		for (int row = 1; row < n; ++row)
			tmp_res[tmp_idx++ % ARR_SIZE] = origin_arr[(m + depth * 2) * row + m - 1];
		for (int col = m - 2; col >= 0; --col)
			tmp_res[tmp_idx++ % ARR_SIZE] = origin_arr[(m + depth * 2) * (n - 1) + col];
		for (int row = n - 2; row > 0; --row)
			tmp_res[tmp_idx++ % ARR_SIZE] = origin_arr[(m + depth * 2) * row];

		// copy to res_arr
		tmp_idx = 0;
		for (int col = 0; col < m; ++col)
			res_arr[col] = tmp_res[tmp_idx++];
		for (int row = 1; row < n; ++row)
			res_arr[row * (m + depth * 2) + m - 1] = tmp_res[tmp_idx++];
		for (int col = m - 2; col >= 0; --col)
			res_arr[(m + depth * 2) * (n - 1) + col] = tmp_res[tmp_idx++];
		for (int row = n - 2; row > 0; --row)
			res_arr[(m + depth * 2) * row] = tmp_res[tmp_idx++];

		origin_arr = origin_arr + m + depth * 2 + 1;
		res_arr = res_arr + m + depth * 2 + 1;
		n -= 2;
		m -= 2;
		++depth;
	}
}

void	my_printer(const int &n, const int &m)
{
	for (int row = 0; row < n; ++row, cout << "\n")
	{
		for (int col = 0; col < m; ++col, cout << " ")
		{
			cout << arr[row * m + col];
		}
	}
}

void	get_input(int &n, int &m, int &r)
{
	string	input;
	// get N
	cin >> input;
	n = stoi(input);
	// get L
	cin >> input;
	m = stoi(input);
	cin >> input;
	// get R
	r = stoi(input);
	// get arr
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cin >> input;
			arr[row * m + col] = stoi(input);
		}
	}
}

int	main(void)
{
	int n, m, r;
	cin.tie(0);
	ios::sync_with_stdio(0);
	get_input(n, m , r);
	solver(n, m, r, arr, arr);
	my_printer(n, m);
	return (0);
}
