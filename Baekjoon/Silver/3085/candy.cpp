#include <iostream>
#include <string>
#include <vector>

// #define _N_MAX_ 50
typedef unsigned int	MapSize;

using namespace std;

enum CANDY_COLOR
{
	COLOR_RED = 'C',
	COLOR_BLUE = 'P',
	COLOR_GREEN = 'Z',
	COLOR_YELLOW = 'Y'
};

template<class ItemType>
void	swapPosition(ItemType &a, ItemType &b)
{
	ItemType temp;
	temp = a;
	a = b;
	b = temp;
}

void	getInput(MapSize &mapSize, vector<string> &candyGameMap)
{
	string	input;

	cin >> mapSize;
	for (MapSize idx = 0; idx < mapSize; ++idx)
	{
		cin >> input;
		candyGameMap.push_back(input);
	}
}

int	getMaxCandyResult(const MapSize &MAP_SIZE, const vector<string> &CANDY_GAME_MAP)
{
	int	max = 0;

	for (MapSize row = 0; row < MAP_SIZE; ++row)
	{
		int sequenceNumbers = 1;
		for (MapSize col = 0; col < MAP_SIZE - 1; ++col)
		{
			if (CANDY_GAME_MAP[row][col] == CANDY_GAME_MAP[row][col + 1])
			{
				++sequenceNumbers;
				max = max < sequenceNumbers ? sequenceNumbers : max;
			}
			else
			{
				sequenceNumbers = 1;
			}
		}
	}
	for (MapSize col = 0; col < MAP_SIZE; ++col)
	{
		int sequenceNumbers = 1;
		for (MapSize row = 0; row < MAP_SIZE - 1; ++row)
		{
			if (CANDY_GAME_MAP[row][col] == CANDY_GAME_MAP[row + 1][col])
			{
				++sequenceNumbers;
				max = max < sequenceNumbers ? sequenceNumbers : max;
			}
			else
			{
				sequenceNumbers = 1;
			}
		}
	}
	return (max);
}

void printMap(const vector<string> &CANDY_GAME_MAP)
{
	for (MapSize row = 0; row < CANDY_GAME_MAP.size(); ++row)
	{
		cout << CANDY_GAME_MAP[row] << endl;
	}
	cout << endl;
}

void swapRight(const int row, const int col, const vector<string> &CANDY_GAME_MAP, vector<string> &swappedMap)
{
	swappedMap = CANDY_GAME_MAP;
	swapPosition(swappedMap[row][col], swappedMap[row][col + 1]);
	// printMap(swappedMap);
}

void swapDown(const int row, const int col, const vector<string> &CANDY_GAME_MAP, vector<string> &swappedMap)
{
	swappedMap = CANDY_GAME_MAP;
	swapPosition(swappedMap[row][col], swappedMap[row + 1][col]);
	// printMap(swappedMap);
}

int	solver(const MapSize &MAP_SIZE, const vector<string> &CANDY_GAME_MAP)
{
	int	maxResult = getMaxCandyResult(MAP_SIZE, CANDY_GAME_MAP);
	// BRUTE FORCE
	for (MapSize row = 0; row < MAP_SIZE; ++row)
	{
		for (MapSize col = 0; col < MAP_SIZE; ++col)
		{
			vector<string>	swappedMap;
			int	maxCandyOfMap;
			if (col < MAP_SIZE - 1)
			{
				swapRight(row, col, CANDY_GAME_MAP, swappedMap);
				maxCandyOfMap = getMaxCandyResult(MAP_SIZE, swappedMap);
				maxResult = maxResult < maxCandyOfMap ? maxCandyOfMap : maxResult;
			}
			if (row < MAP_SIZE - 1)
			{
				swapDown(row, col, CANDY_GAME_MAP, swappedMap);
				maxCandyOfMap = getMaxCandyResult(MAP_SIZE, swappedMap);
				maxResult = maxResult < maxCandyOfMap ? maxCandyOfMap : maxResult;
			}
		}
	}
	return (maxResult);
}

int	main(void)
{
	vector<string>	candyGameMap;
	MapSize	mapSize;

	getInput(mapSize, candyGameMap);
	cout << solver(mapSize, candyGameMap);
}
