#include <iostream>
#include <string>
#include <memory.h>

int	map_info[100][100];

int	move(int row, int col, int map_size, const int height, int visited[100][100])
{
	if (row >= map_size || col >= map_size)
		return (1);
	if (map_info[row][col] <= height || visited[row][col])
		return (1);
	visited[row][col] = true;
	return (
			move(row + 1, col, map_size, height, visited) 
			+ move(row, col + 1, map_size, height, visited) 
			+ move(row - 1, col, map_size, height, visited) 
			+ move(row, col - 1, map_size, height, visited)
			);
}

int	explorer(const int map_size, const int height, int visited[100][100])
{
	int	result = 0;
	int	size;

	for (int row = 0; row < map_size; ++row)
	{
		for (int col = 0; col < map_size; ++col)
		{
			if (visited[row][col])
				continue;
			size = move(row, col, map_size, height, visited);
			result = size > 1 ? result + 1 : result;
		}
	}
	return (result);
}

int	solver(const int map_size)
{
	int	max = 0;
	int	res;
	int	visited[100][100];

	for (int height = 1; height <= 100; ++height)
	{
		memset(visited, 0, sizeof(int) * 100 * 100);
		res = explorer(map_size, height, visited);
		max = max < res ? res : max;
	}
	return (max);
}

void	get_input(int &map_size)
{
	using namespace std;
	string	input; 

	cin >> input;
	map_size = stoi(input);
	for (int i = 0; i < map_size; ++i)
	{
		for (int j = 0; j < map_size; ++j)
		{
			cin >> input;
			map_info[i][j] = stoi(input);
		}
	}
}

/*
#include <random>
void	make_case()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			std::cout << std::rand() % 10 << " ";
		}
		std::cout << "\n";
	}
}
*/

int	main(void)
{
	int	map_size;
	int	res;

	get_input(map_size);
	res = solver(map_size);
	//make_case();
	std::cout << res;
	return(res);
}
