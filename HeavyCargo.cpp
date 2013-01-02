#include <iostream>
#include <string>
#include <map>
#include <climits>

using namespace std;

int max(int a, int b)
{
	return a<b ? b : a;
}

int min(int a, int b)
{
	return a<b ? a : b;
}
int MaxLoadDFS(int s, int t, int size, int** weights)
{
	for (int k=0; k<size; k++)
	{
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				if (weights[i][k]!=-1 && weights[k][j]!=-1)
				{
					weights[i][j] = max(weights[i][j], min(weights[i][k], weights[k][j]));
				}
			}
		}
	}
	return weights[s][t];
}

int main()
{
	int n=0, r=0;
	map<string, int> city_map;
	int idx = 0;
	int i, j;
	cin >> n >> r;
	int case_no = 1;
	int** weights = 0;
	while (n>0 && r>0)
	{
		weights = new int*[n];
		idx = 0;
		for (i=0; i<n; i++)
		{
			weights[i] = new int[n];
			for (j=0; j<n; j++)
			{
				weights[i][j] = -1;
			}
		}
		string city_1, city_2;
		int weight = 0;
		int idx_1=0, idx_2=0;
		for (i=0; i<r; i++)
		{
			cin >> city_1 >> city_2 >> weight;
			if (city_map.find(city_1) != city_map.end())
			{
				idx_1 = city_map[city_1];
			}
			else
			{
				city_map[city_1] = idx;
				idx_1 = idx;
				idx++;
			}
			if (city_map.find(city_2) != city_map.end())
			{
				idx_2 = city_map[city_2];
			}
			else
			{
				city_map[city_2] = idx;
				idx_2 = idx;
				idx++;
			}
			weights[idx_1][idx_2] = weight;
			weights[idx_2][idx_1] = weight;
		}
		cin >> city_1 >> city_2;
		idx_1 = city_map[city_1];
		idx_2 = city_map[city_2];
		cout << "Scenario #" << case_no++ << endl;
		cout << MaxLoadDFS(idx_1, idx_2, n, weights) << " tons" << endl;
		cout << endl;
		for (i=0; i<n; i++)
		{
			delete[] weights[i];
		}
		delete[] weights;
		weights = 0;
		cin >> n >> r;
	}
	return 0;
}