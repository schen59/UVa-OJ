#include <iostream>
using namespace std;

int main()
{
	int combi[101][101];
	for (int i=0; i<=100; i++)
	{
		for (int j=0; j<=100; j++)
		{
			if (i==j)
			{
				combi[i][j] = 1;
			}
			else if (j==0)
			{
				combi[i][j] = 1;
			}
			else if (j>i)
			{
				break;
			}
			else
			{
				combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
			}
		}
	}
	int n = 0;
	int m = 0;
	cin >> n >> m;
	while (n>0 && m>0)
	{
		cout << n << " things taken " << m << " at a time is " << combi[n][m] << " exactly." << endl;
		cin >> n >> m;
	}
	return 0;
}