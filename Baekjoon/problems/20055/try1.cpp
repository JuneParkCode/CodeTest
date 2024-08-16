#include <iostream>
#include <string>
using namespace std;

// STRUCTS
typedef	struct	s_spot
{
	int	dur;
	int	empty;
}				t_spot;

// GLOBAL_VARS
t_spot		spots[200];
int			n;
int			k;
int			steps;

// FUNCTIONS

int	get_pos(int pos, int n)
{
	pos = pos % (2 * n);
	while (pos < 0)
		pos += 2 * n;
	return (pos);
}

t_spot	make_spot(int dur)
{
	t_spot	spot;
	
	spot.dur = dur;
	spot.empty = 1;
	return (spot);
}

void	get_input()
{
	string	input;
	int		dur;

	cin >> input;
	n = stoi(input);

	cin >> input;
	k = stoi(input);
	
	for (int i = 0; i < (2 * n); ++i)
	{
		cin >> input;
		dur = stoi(input);
		spots[i] = make_spot(dur);
	}
}

void	insert_robot()
{
	t_spot	*push_spot;
	int		pos;

	pos = get_pos(2 * n - steps, n) % (2 * n);
	push_spot = &spots[pos];
	if (push_spot -> dur == 0 || push_spot -> empty == 0)
		return ;
	push_spot -> empty = 0;
	(push_spot -> dur)--;
	k -= (push_spot -> dur == 0);
}

void	drop_robot()
{
	t_spot	*drop_spot;
	int		pos;

	pos = get_pos(n - 1 - steps, n) % (2 * n);
	drop_spot = &spots[pos];
	drop_spot -> empty = 1;
}

void	move_cov()
{
	++steps;
}

void	move_robots()
{
	t_spot	*cur;
	t_spot	*next;
	int		pos;

	for (int count = 0; count < n; ++count)
	{
		pos = get_pos(n - 1 - steps - count, n) % (2 * n);
		cur = &spots[pos];
		next = &spots[(pos + 1) % (2 * n)];
		if (cur -> empty == 0 && next -> empty && next -> dur)
		{
			(cur -> empty) = 1;
			(next -> dur)--;
			(next -> empty) = 0;
			k -= (next -> dur == 0);
		}
	}
}

void	print_conv()
{
	int	i;

	cout << "STEP " << steps << endl;
	for (int count = 0; count < n; ++count)
	{
		i = get_pos(2 * n - steps + count, n) % (2 * n);
		cout << "[" << spots[i].dur << "," << spots[i].empty << "]" << i << " ";
	}
	cout << endl;
	for (int count = 0; count < n; ++count)
	{
		i = get_pos(2 * n - 1 - steps - count, n) % (2 * n);
		cout << "[" << spots[i].dur << "," << spots[i].empty << "]" << i << " ";
	}
	cout << endl;
}

void	work()
{
	//print_conv();
	move_cov();
	drop_robot();
	move_robots();
	drop_robot();
	insert_robot();
}

int	main(void)
{
	get_input();
	steps = 0;
	while (k > 0)
		work();
	cout << (steps);
	return (0);
}
