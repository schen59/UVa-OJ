#include <iostream>
#include <cmath>
using namespace std;

bool Prime(int j)
{
	if (j==2)
	{
		return true;
	}
	if (j%2 == 0)
	{
		return false;
	}
	for (int i=3; i<=sqrt(j); i++)
	{
		if (j%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int g = 0;
	cin >> g;
	while (g != 0)
	{
		if (g < 0)
		{
			cout << g << " = -1 x ";
			g = -g;
		}
		else
		{
			cout << g << " = ";
		}
		while (g > 1)
		{
			if (Prime(g))
			{
				cout << g << endl;
				break;
			}
			for (int j=2; j<=sqrt(g); j++)
			{
				if (j!=2 && j%2==0)
				{
					continue;
				}
				if (g%j == 0 && Prime(j))
				{
					cout << j << " x ";
					g /= j;
					break;
				}
			}
		}
		cin >> g;
	}
	return 0;
}