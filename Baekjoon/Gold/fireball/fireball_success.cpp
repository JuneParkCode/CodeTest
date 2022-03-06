#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef	struct s_fireball
{
	pair<int, int>	pos;
	int				mass;
	int				speed;
	int				direction;
}		t_fireball;

typedef vector<t_fireball> t_fireballs;
typedef vector<vector<t_fireballs>> t_map;

const int row_dir[] = {-1,-1,0,1,1,1,0,-1};
const int col_dir[] = {0,1,1,1,0,-1,-1,-1};
int 				N, M, K;

t_fireball	make_fireball(int row, int col, int mass, int speed, int direction)
{
	t_fireball	new_ball;

	new_ball.pos = {row, col};
	new_ball.mass = mass;
	new_ball.speed = speed;
	new_ball.direction = direction;
	return (new_ball);
}

void	get_nmk()
{
	string  input;

	cin >> input;
	N = stoi(input);
	cin >> input;
	M = stoi(input);
	cin >> input;
	K = stoi(input);
}

t_map	get_map()
{
	t_map	new_map;

	for (int row = 0; row < N; ++row)
	{
		vector<t_fireballs>	new_row;
		new_map.push_back(new_row);
		for (int col = 0; col < N; ++col)
		{
			t_fireballs	new_pos;
			new_row.push_back(new_pos);
		}
	}
	return (new_map);
}

void	get_fireballs(t_map *current_map, t_fireballs *exist_balls)
{
	string	input;
	int		r, c, m, s, d;

	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		r = stoi(input) - 1;
		cin >> input;
		c = stoi(input) - 1;
		cin >> input;
		m = stoi(input);
		cin >> input;
		s = stoi(input);
		cin >> input;
		d = stoi(input);
		if (m <= 0)
			continue;
		t_fireball new_ball = make_fireball(r, c, m ,s ,d);
		(*current_map)[r][c].push_back(new_ball);
		exist_balls -> push_back(new_ball);
	}
}

int	get_right_pos(int point)
{
	if (point >= N)
	{
		return (point % N);
	}
	else if (point < 0)
	{
		while (point < 0)
		{
			point += N;
		}
		return (point);
	}
	else
	{
		return (point);
	}
}

void	move_balls(t_map *current_map, t_map *after_map, t_fireballs *exist_balls, t_fireballs *balls_temp)
{
	int	row, col;
	int	tmp_row, tmp_col;
	int	new_row, new_col;

	for (auto ball : *exist_balls)
	{
		row = ball.pos.first;
		col = ball.pos.second;
		tmp_row = row + row_dir[ball.direction] * ball.speed;
		tmp_col = col + col_dir[ball.direction] * ball.speed;
		new_row = get_right_pos(tmp_row);
		new_col = get_right_pos(tmp_col);

		t_fireball new_ball = make_fireball(new_row, new_col, ball.mass, ball.speed, ball.direction);
		balls_temp->push_back(new_ball);
		// cout << new_row << "," << new_col <<endl;
		(*after_map)[new_row][new_col].push_back(new_ball);
		(*current_map)[row][col].clear();
	}
	exist_balls -> clear();
	// for (auto ball : *balls_temp)
	// {
	// 	cout << ball.pos.first << "," << ball.pos.second << " | ";
	// 	cout << ball.mass << "," << ball.speed << "," << ball.direction <<endl;
	// }
	// cout << "====temp===="<<endl;
}

void	get_next(t_map *current_map, t_map *after_map, t_fireballs *exist_balls, t_fireballs *balls_temp)
{
	for (auto ball : *balls_temp)
	{
		int		row = ball.pos.first;
		int		col = ball.pos.second;
		int		mass = 0;
		int		speed = 0;
		int		count = 0;
		bool	even = 1;
		bool	odd = 1;

		t_fireballs *pos = &(*after_map)[row][col];
		for (auto target_ball : *pos)
		{
			mass += target_ball.mass;
			speed += target_ball.speed;
			count++;
			even = even ? target_ball.direction % 2 == 0 : 0;
			odd = odd ? target_ball.direction % 2 == 1 : 0;
		}
		if ((*current_map)[row][col].size() != 0)
			continue;
		if (count == 1)
		{
			t_fireball	new_ball = make_fireball(row, col, mass, speed, (*pos)[0].direction);
			(*current_map)[row][col].push_back(new_ball);
			exist_balls -> push_back(new_ball);
		}
		else if (count > 1)
		{
			bool	flag = !(odd || even);
			mass = mass / 5;
			speed = speed / count;
			if (mass)
			{
				for (int i = 0; i < 4; ++i)
				{
					t_fireball	new_ball = make_fireball(row, col, mass, speed, i * 2 + flag);
					(*current_map)[row][col].push_back(new_ball);
					exist_balls -> push_back(new_ball);
				}
			}
		}
		pos -> clear();
	}
	balls_temp -> clear();
}

int main(void)
{
	get_nmk();

	t_fireballs	exist_balls;	// 편리하게 fireballs를 접근하기 위함.
	t_fireballs	balls_temp;
	t_map		current_map(N, vector<t_fireballs>(N));
	t_map		after_map(N, vector<t_fireballs>(N));		// 중복케이스 처리를 위함

	get_fireballs(&current_map, &exist_balls);
	// for (auto ball : exist_balls)
	// {
	// 	cout << ball.pos.first << "," << ball.pos.second << " | ";
	// 	cout << ball.mass << "," << ball.speed << "," << ball.direction <<endl;
	// }
	// cout << "========"<<endl;
	for (int tries; tries < K ; tries++)
	{
		// cout << "LOOP" << tries << endl;
		move_balls(&current_map, &after_map, &exist_balls, &balls_temp);
		get_next(&current_map, &after_map, &exist_balls, &balls_temp);
		// for (auto ball : exist_balls)
		// {
		// 	cout << ball.pos.first << "," << ball.pos.second << " | ";
		// 	cout << ball.mass << "," << ball.speed << "," << ball.direction <<endl;
		// }
		// cout << "========"<<endl;
	}
	int	mass = 0;
	for (auto ball : exist_balls)
	{
		mass += ball.mass;
	}
	cout << mass;
}