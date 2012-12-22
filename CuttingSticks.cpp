#include <iostream>
using namespace std;

int OptimalCuts(int l, int* cuts, int size)
{
	int** opt_cuts = new int*[size];
	int i = 0;
	int j = 0;
	int k = 0;
	int diag = 0;
	int min_cost = 2147483647;
	for (i=0; i<size; i++)
	{
		opt_cuts[i] = new int[size];
		if (i < size-1)
		{
			opt_cuts[i][i+1] = 0;
		}
	}

	for (diag=1; diag<=size-2; diag++)
	{
		for (i=0, j=diag+1; i<=size-diag-2 && j<=size-1; i++, j++)
		{
			if (i>=j)
			{
				continue;
			}
			min_cost = 2147483647;
			for (k=i+1; k<j; k++)
			{
				if (opt_cuts[i][k]+opt_cuts[k][j] < min_cost)
				{
					min_cost = opt_cuts[i][k] + opt_cuts[k][j];
				}
			}
			opt_cuts[i][j] = min_cost + cuts[j] - cuts[i];
		}
	}
	min_cost = opt_cuts[0][size-1];
	for (i=0; i<size; i++)
	{
		delete[] opt_cuts[i];
	}
	delete[] opt_cuts;
	opt_cuts = 0;
	return min_cost;
}

int main()
{
	int l = 0;
	cin >> l;
	int* cuts = 0;
	while (l > 0)
	{
		int n = 0;
		cin >> n;
		cuts = new int[n+2];
		cuts[0] = 0;
		cuts[n+1] = l;
		for (int i=1; i<=n; i++)
		{
			cin >> cuts[i];
		}
		cout << "The minimum cutting is " << OptimalCuts(l, cuts, n+2) << "." << endl;
		delete[] cuts;
		cuts = 0;
		cin >> l;
	}
	return 0;
}