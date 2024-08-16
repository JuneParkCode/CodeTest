#include <string>
#include <iostream>

using namespace std;

// n, m <= 300

int	arr[300 * 300];
int	res[300 * 300];

void	solver(const int n, const int m, const int r, int *origin_arr, int *res_arr, int depth)
{
	if (n < 2 || m < 2)
		return ;
	
	const int	ARR_SIZE = 2 * (n + m) - 4;
	const int	ROTATION = r % ARR_SIZE;
	int			start_row = 0;
	int			start_col = 0;

	if (ROTATION < m)
	{
		start_col = ROTATION;
		start_row = 0;
	}
	else if (ROTATION < (n + m))
	{
		start_col = n - 1;
		start_row = (ROTATION - (n - 1));
	}
	else if (ROTATION < (n + m + m))
	{
		start_col = n - (ROTATION - (n + m - 1));
		start_row = m - 1;
	}
	else
	{
		start_col = 0;
		start_row = m - (ROTATION - (n + m + n - 1));
	}
	int	res_idx= start_row * m + start_col;
	int	tmp_res[ARR_SIZE];

	// copy as 1-dimension ARR
	for (int col = 0; col < m; ++col)
		tmp_res[res_idx++ % ARR_SIZE] = origin_arr[col];
	for (int row = 1; row < n; ++row)
		tmp_res[res_idx++ % ARR_SIZE] = origin_arr[(m + depth * 2) * row + m - 1];
	for (int col = m - 2; col >= 0; --col)
		tmp_res[res_idx++ % ARR_SIZE] = origin_arr[(m + depth * 2)* (n - 1) + col];
	for (int row = n - 2; row > 0; --row)
		tmp_res[res_idx++ % ARR_SIZE] = origin_arr[(m + depth * 2) * row];

	// copy to res_arr
	res_idx = 0;
	for (int col = 0; col < m; ++col)
		res_arr[col] = tmp_res[res_idx++];
	for (int row = 1; row < n; ++row)
		res_arr[row * (m + depth * 2) + m - 1] = tmp_res[res_idx++];
	for (int col = m - 2; col >= 0; --col)
		res_arr[(m + depth * 2) * (n - 1) + col] = tmp_res[res_idx++];
	for (int row = n - 2; row > 0; --row)
		res_arr[(m + depth * 2) * row] = tmp_res[res_idx++];

	solver(n - 2, m - 2, r, origin_arr + m  + 1, res_arr + m + 1, ++depth);
}

void	printer(const int &n, const int &m)
{
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < m; ++col)
		{
			cout << res[row * m + col] << " ";
		}
		cout << "\n";
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
    get_input(n, m , r);
    solver(n, m, r, arr, res, 0);
	printer(n, m);
	return (0);
}
