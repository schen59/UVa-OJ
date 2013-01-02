#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int GCD(int a, int b)
{
	//if (a < b)
	//{
	//	Swap(a, b);
	//}
	if (b == 0)
	{
		return a;
	}
	return GCD(b, a%b);
}

int main()
{
	int N = 0;
	cin >> N;
	while (N > 0)
	{
		int* rand_nums = new int[N];
		int i, j;
		for (i=0; i<N; i++)
		{
			cin >> rand_nums[i];
		}
		int total = 0;
		int pairs = 0;
		for (i=0; i<N; i++)
		{
			for (j=i+1; j<N; j++)
			{
				total++;
				if (GCD(rand_nums[i], rand_nums[j]) == 1)
				{
					pairs++;
				}
			}
		}
		if (pairs == 0)
		{
			cout << "No estimate for this data set." << endl;
		}
		else
		{
			cout << fixed;
			cout << setprecision(6) << sqrt(6.0*total/pairs) << endl;
			//cout << "No estimate for this data set." << endl;
		}
		delete[] rand_nums;
		rand_nums = 0;
		cin >> N;
	}
	return 0;
}