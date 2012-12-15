#include <iostream>
using namespace std;

int MaximumSum(int** array, int number)
{
	int max_sum  = 1<<31;
    int* col_sum = new int[number];
	for (int row=0; row<number; row++)
	{
		for (int i=0; i<number; i++)
		{
			col_sum[i] = 0;
		}
		for (int r=row; r<number; r++)
		{
			int max_col_sum = 1<<31;
			int cur_col_sum = 0;
			for (int c=0; c<number; c++)
			{
				col_sum[c]  += array[r][c];
                cur_col_sum += col_sum[c];
				if (cur_col_sum > max_col_sum)
				{
					max_col_sum = cur_col_sum;
				}
				if (cur_col_sum < 0)
				{
					cur_col_sum = 0;
				}
			}
			if (max_col_sum > max_sum)
			{
				max_sum = max_col_sum;
			}
		}
	}
	return max_sum;
}

int main()
{
	int** array = 0;
	int number = 0;
	cin >> number;
	array = new int*[number];
	for (int i=0; i<number; i++)
	{
		array[i] = new int[number];
		for (int j=0; j<number; j++)
		{
			cin >> array[i][j];
		}
	}
	cout << MaximumSum(array, number) << endl;
	return 0;
}