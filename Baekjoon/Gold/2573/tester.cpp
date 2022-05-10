#include <iostream>
#include <random>

using namespace std;

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	int	n, m;
	
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	cout << endl;
	for (int i = 0; i < n; ++i, cout << "\n")
	{
		for (int j = 0; j < m; ++j, cout << " ")
		{
			if (i == 0 || j == 0 || i == (n - 1) || j == (m - 1))
				cout << 0;
			else
				cout << random() % 10;
		}
	}
}
