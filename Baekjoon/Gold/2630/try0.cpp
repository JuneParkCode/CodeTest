#include <iostream>
#include <string>

using namespace std;

bool	paper[128][128];
int		n;
int		white;
int		blue;

void	get_input()
{
	string	input;

	cin >> input;
	n = stoi(input);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> input;
			paper[i][j] = stoi(input); 
		}
	}
}

void	get_color_paper(int row, int col, int size)
{
	bool	is_white;
	bool	is_blue;

	if (size == 0)
		return ;
	is_white = 1;
	is_blue = 1;
	for (int r = row; r < size + row; ++r)
	{
		for (int c = col; c < size + col; ++c && (is_white || is_blue))
		{
			is_white = is_white ? !paper[r][c] : 0;
			is_blue = is_blue ? paper[r][c] : 0;
		}
	}
	if (!is_white && !is_blue)
	{
		get_color_paper(row, col, size / 2);
		get_color_paper(row + size / 2, col, size / 2);
		get_color_paper(row, col + size / 2, size / 2);
		get_color_paper(row + size / 2, col + size / 2, size / 2);
	}
	white += is_white;
	blue += is_blue;
}

void	solver()
{
	get_color_paper(0, 0, n);
}

void	print()
{
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			cout << paper[r][c];
		}
		cout << endl;
	}
}

int	main(void)
{
	n = white = blue = 0;
	get_input();
	solver();
	cout << white << endl;
	cout << blue;
	return (0);
}
