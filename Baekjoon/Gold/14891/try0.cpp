#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// define limits
#define NUMBER_OF_GEAR 4
#define NUMBER_OF_TOOTH 8
#define LIMITS_OF_COMMAND 100

// define
#define LEFT 6
#define RIGHT 2
#define CW 1
#define CCW -1
#define S 1
#define N 0

// global variables
typedef pair<int, int> t_command;
int			gears[NUMBER_OF_GEAR][NUMBER_OF_TOOTH];	// gear Information
int			gear_state[NUMBER_OF_GEAR];				// gear status (start point of array)
t_command	command[LIMITS_OF_COMMAND];				// commands
int			numberOfCommand;						// number of commands

void	setPosition(int gearNumber, int direction)
{
	int	&status = gear_state[gearNumber];
	if (direction == CW)
	{
		--status;
	}
	else
	{
		++status;
	}
	if (status < 0)
		status += NUMBER_OF_TOOTH;
	else if (status >= NUMBER_OF_TOOTH)
		status -= NUMBER_OF_TOOTH;
	//cout << gearNumber << " -> " << status <<endl;
}

void	setPositionGears(vector<t_command> &cmds)
{
	for (t_command &cmd : cmds)
	{
		setPosition(cmd.first, cmd.second);
	}
}

int	getPositionOfTooth(int gearNumber, int position)
{
	int res;

	res = (position + gear_state[gearNumber]);
	if (res >= NUMBER_OF_TOOTH)
		res -= NUMBER_OF_TOOTH;
	else if (res < 0)
		res += NUMBER_OF_TOOTH;
	return (res);
}

// do command and rotate
void	rotate(t_command cmd)
{
	int					direction;
	vector<t_command> 	targets;

	direction = cmd.second;
	// rotate left gears
	for (int i = cmd.first; i >= 0; --i)
	{
		t_command	p (i, direction);
		targets.push_back(p);
		//cout << i + 1 << " -roated : " << direction <<endl;
		if (i == 0)
		{
			break ;
		}
		direction *= -1;
		if (gears[i - 1][getPositionOfTooth(i - 1, RIGHT)] == gears[i][getPositionOfTooth(i, LEFT)])
		{
			break ;
		}
	}
	direction = cmd.second;
	// rotate right gears
	for (int i = cmd.first; i < NUMBER_OF_GEAR; ++i)
	{
		if (i != cmd.first)
		{
			t_command	p (i, direction);
			targets.push_back(p);
			//cout << i + 1 << " +roated : " << direction <<endl;
		}
		if (i == NUMBER_OF_GEAR - 1)
		{
			break ;
		}
		direction *= -1;
		if (gears[i + 1][getPositionOfTooth(i + 1, LEFT)] == gears[i][getPositionOfTooth(i, RIGHT)])
		{
			break ;
		}
	}
	setPositionGears(targets);
}

// @return sum of score
int	getScore()
{
	int	mult;
	int	sum;

	mult = 1;
	sum = 0;
	for (int i = 0; i < NUMBER_OF_GEAR; ++i)
	{
		//cout << i << " : " << gears[i][gear_state[i]] << endl;
		sum += (gears[i][gear_state[i]]) * mult;
		mult *= 2;
	}
	return (sum);
}

// @return score
int	solver()
{
	for (int i = 0; i < numberOfCommand; ++i)
	{
		rotate(command[i]);
		//cout << "===\n";
	}
	return (getScore());
}

// get input
void	getInput()
{
	string	input;
	int		gear_n;		// gear_number
	int		direction;	// direction (CCW or CW) 
	// get gear information
	for (int i = 0; i < NUMBER_OF_GEAR; ++i)
	{
		cin >> input;
		for (int j = NUMBER_OF_TOOTH - 1; j >= 0; --j)
		{
			gears[i][j] = input[j] - '0';
		}
	}
	// get number of command
	cin >> input;
	numberOfCommand = stoi(input);
	// get rotation direction
	for (int i = 0; i < numberOfCommand; ++i)
	{
		cin >> input;
		gear_n = stoi(input) - 1;
		cin >> input;
		direction = stoi(input);
		command[i] = pair<int, int> (gear_n, direction);
	}
}

void	initGear()
{
	for (int i = 0; i < NUMBER_OF_GEAR; ++i)
	{
		gear_state[i] = 0;
		//cout << "status : " << i << gear_state[i] <<endl;
	}
}

int	main(void)
{
	getInput();
	initGear();
	cout << solver();
	return (0);
}
