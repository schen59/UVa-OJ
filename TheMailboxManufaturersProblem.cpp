#include <iostream>
#include <climits>
using namespace std;
int min_c[11][101][101];
int max(int a, int b)
{
	return a<b ? b : a;
}

int min(int a, int b)
{
	return a<b ? a : b;
}

int minCrakers(int k, int low, int high)
{
	
	if (min_c[k][low][high] != -1)
	{
		return min_c[k][low][high];
	}
	if (k == 0)
	{
		//cout << k << " " << low << " " << high << " yes" << endl;
		min_c[k][low][high] = INT_MAX;
		return INT_MAX;
	}
	if (k == 1)
	{
		//cout << k << " " << low << " " << high << " yes" << endl;
		min_c[k][low][high] = (low+high)*(high-low+1)/2;
		return (low+high)*(high-low+1)/2;
	}
	if (low == high)
	{
		//cout << k << " " << low << " " << high << " yes" << endl;
		min_c[k][low][high] = low;
		return low;
	}
	int min_cracker = (low+high)*(high-low+1)/2;
	for (int i=low+1; i<high; i++)
	{
		min_cracker = min(min_cracker, i+max(minCrakers(k-1, low, i-1), minCrakers(k, i+1, high)));
	}
	//cout << k << " " << low << " " << high << " yes" << endl;
	min_c[k][low][high] = min_cracker;
	return min_cracker;
}

int main()
{
	int t = 0;
	int k = 0;
	int m = 0;
	cin >> t;
	for (int i=0; i<t; i++)
	{
		cin >> k >> m;
		for (int o=0; o<11; o++)
		{
			for (int p=0; p<101; p++)
			{
				for (int q=0; q<101; q++)
				{
					min_c[o][p][q] = -1;
				}
			}
		}
		cout << minCrakers(k, 0, m) << endl;
	}
	
	return  0;
}