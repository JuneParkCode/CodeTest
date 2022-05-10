#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

using namespace std;

// n, m <= 300

int	test_arr[300 * 300];
int	test_arr2[300][300];

void	solver(int n, int m, const int r, int *origin_arr, int *res_arr)
{
	int	depth = 0;

	while (n >= 2 && m >= 2)
	{
		int	ARR_SIZE = 2 * (n + m) - 4;
		int	ROTATION = r % ARR_SIZE;
		int	tmp_res[ARR_SIZE];
		int	tmp_idx = (ARR_SIZE - ROTATION) % ARR_SIZE;

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
			res_arr[(m + depth * 2) * row + m - 1] = tmp_res[tmp_idx++];
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

void	solver2(int n, int m, int r, int d[][300])
{
	// 회전방향 : 왼쪽, 위, 오른쪽, 아래
    while (r--) {
        int x1 = 0;
        int y1 = 0;

        int x2 = n-1;
        int y2 = 0;

        int x3 = n-1;
        int y3 = m-1;

        int x4 = 0;
        int y4 = m-1;
        while ( (x1 < x2) && (y1 < y4) ) {
            int tmp = d[x2][y2];
            for (int i = x2; i > x1; i--) {
                d[i][y2] = d[i-1][y2];
            }
            for (int j = y1; j < y4; j++) {
                d[x1][j] = d[x1][j+1];
            }
            for (int i = x4; i < x3; i++) {
                d[i][y4] = d[i+1][y4];
            }
            for (int j = y3; j > y2; j--) {
                d[x3][j] = d[x3][j-1];
            }
            d[x2][y2+1] = tmp;
            x1 += 1;
            y1 += 1;

            x2 -= 1;
            y2 += 1;

            x3 -= 1;
            y3 -= 1;

            x4 += 1;
            y4 -= 1;
        }
    }
}

void	my_printer(const int &n, const int &m)
{
	for (int row = 0; row < n; ++row, cout << "\n")
	{
		for (int col = 0; col < m; ++col, cout << " ")
		{
			cout << test_arr[row * m + col];
		}
	}
}

void	solverPrinter(const int &n, const int &m, int d[][300])
{
	for (int i = 0; i< n; i++, cout << "\n")
	{
        for (int j = 0; j< m; j++)
            cout << d[i][j] << " ";
    }
    cout << endl;
}

void	isEQUAL(int n, int m)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (test_arr[i * m + j] != test_arr2[i][j])
			{
				cout << "NOT EQUAL IN : " << i << ", " << j <<endl;
				cout << "ANS" <<endl;
				solverPrinter(n, m, test_arr2);
				cout << "MINE" <<endl;
				my_printer(n, m);
				return ;
			}
		}
	}
	cout << "EQAUL" << endl;
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	const int	N = atoi(argv[1]);
	const int	M = atoi(argv[2]);
	srand((unsigned int)time(NULL));

	const int	R = rand() % 1000;
	cout << N << " " << M << " " << R << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int x = rand() % 10;
			test_arr[i * M + j] = x;
			test_arr2[i][j] = x;
		}
	}
	/*
	cout << "INIT MINE" <<endl;
	my_printer(N, M);
	cout << "INIT ANS" <<endl;
	solverPrinter(N, M, test_arr2);
	*/
	solver(N, M, R, test_arr, test_arr);
	solver2(N, M, R, test_arr2);
	isEQUAL(N, M);
	
	return (0);
}
