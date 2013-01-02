#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n && n>0)
	{
		int** matrix = new int*[n];
		int* rows = new int[n];
		int* cols = new int[n];
		int i, j;
		for (i=0; i<n; i++)
		{
			matrix[i] = new int[n];
			rows[i] = 0;
			cols[i] = 0;
			for (j=0; j<n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if (matrix[i][j] == 1)
				{
					rows[i]++;
					cols[j]++;
				}
			}
		}
		int row_num = 0;
		int col_num = 0;
		int row_idx = 0;
		int col_idx = 0;
		for (i=0; i<n; i++)
		{
			if (rows[i]%2 != 0)
			{
				row_num++;
				row_idx = i;
			}
			if (cols[i]%2 != 0)
			{
				col_num++;
				col_idx = i;
			}
		}
		if (row_num==0 && col_num==0)
		{
			cout << "OK" << endl;
		}
		else if (row_num==1 && col_num==1)
		{
			cout << "Change bit (" << row_idx+1 << "," << col_idx+1 << ")" << endl;
		}
		else
		{
			cout << "Corrupt" << endl;
		}
		for (i=0; i<n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		delete[] rows;
		delete[] cols;
	}
	return 0;
}