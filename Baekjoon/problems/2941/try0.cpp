#include <iostream>
#include <string>

using namespace std;

int	solver(string &input)
{
	const int	LENGTH = input.length();
	int			idx;
	int			res;
	char		flag;

	idx = 0;
	res = 0;
	flag = 0;
	while (idx <= LENGTH)
	{
		if (idx == LENGTH)
			input[idx] = 0;
		switch (flag)
		{
			case 'c':
				res += (input[idx] != '=' && input[idx] != '-');
				break ;
			case 'x':
				res += (input[idx] != '=') * 2;
				break ;
			case 'd':
				if (input[idx] == 'z')
				{
					flag = 'x';
					++idx;
					continue ;
				}
				res += (input[idx] != '-');
				break ;
			case 'l':
			case 'n':
				res += (input[idx] != 'j');
				break ;
			case 's':
			case 'z':
				res += (input[idx] != '=');
				break ;
		}
		flag = 0;
		switch (input[idx])
		{
			case 'c':
				flag = 'c';
				break ;
			case 'd':
				flag = 'd';
				break ;
			case 'l':
				flag = 'l';
				break ;
			case 'n':
				flag = 'n';
				break ;
			case 's':
				flag = 's';
				break ;
			case 'z':
				flag = 'z';
				break ;
			default :
				++res;
				break;
		}
		++idx;
	}
	return (res - 1);
}


int	main(void)
{
	string	input;

	// get input
	cin >> input;
	cout << solver(input);
	return (0);
}
