#include <iostream>
#include <string>
using namespace std;

int FloydShortestPath(int s, int t, int** adj_matrix, int size)
{
	int INF = 2147483647;
	for (int v=0; v<size; v++)
	{
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				if (adj_matrix[i][v]<INF && adj_matrix[v][j]<INF)
				{
					if (adj_matrix[i][v] + adj_matrix[v][j] < adj_matrix[i][j])
					{
						adj_matrix[i][j] = adj_matrix[i][v] + adj_matrix[v][j];
					}
				}
				
			}
		}
	}
	return adj_matrix[s][t];
}

void Initialize(int** adj_matrix, int size)
{
	int INF = 2147483647;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			adj_matrix[i][j] = INF;
		}
	}
}

int main()
{
	string street;
	int** adj_matrix = new int*[26];
	for (int k=0; k<26; k++)
	{
		adj_matrix[k] = new int[26];
	}
    int degree[26];
	int source = -1;
	int ending = -1;
	int i = 0, j = 0;
	int total_cost = 0;
	for (i=0; i<26; i++)
	{
		degree[i] = 0;
	}
	while (cin >> street)
	{
		if (street.compare("deadend") == 0)
		{
			for (i=0; i<26; i++)
			{
				for (j=0; j<26; j++)
				{
					//cout << adj_matrix[i][j] << endl;
				}
			}
			for (i=0; i<26; i++)
			{
				if (degree[i]%2 != 0)
				{
					if (source == -1)
					{
						source = i;
					}
					else
					{
						ending = i;
					}
				}
			}
			if (source!=-1 && ending!=-1)
			{
				cout << total_cost+FloydShortestPath(source, ending, adj_matrix, 26) << endl;
			}
			else
			{
				cout << total_cost << endl;
			}
			Initialize(adj_matrix, 26);
			for (i=0; i<26; i++)
			{
				degree[i] = 0;
			}
			source = -1;
			ending = -1;
			total_cost = 0;
			continue;
		}
		int weight = street.length();
		total_cost += weight;
		int u = street[0] - 'a';
		int v = street[weight-1] - 'a';
		adj_matrix[u][v] = weight;
		adj_matrix[v][u] = weight;
		degree[u]++;
		degree[v]++;
	}
	return 0;
}