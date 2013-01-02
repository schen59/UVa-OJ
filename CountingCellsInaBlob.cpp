#include <iostream>
#include <cstring>
using namespace std;
char grid[26][26];
int blob_size = 0;
int** visited = 0;

void MaxBlob(int u, int v, int size)
{
	visited[u][v] = true;
	blob_size++;
	for (int i=-1; i<=1; i++)
	{
		for (int j=-1; j<=1; j++)
		{
			if (i==0 && j==0)
			{
				continue;
			}
			if (u+i>=0 && u+i<size && v+j>=0 && v+j<size && grid[u+i][v+j]=='1' && !visited[u+i][v+j])
			{
				MaxBlob(u+i, v+j, size);
			}
		}
	}
}
int main()
{
	int cases = 0;
	cin >> cases;
	
	int size = 0;
	while (cases > 0)
	{
		
		cin >> grid[0];
		int i, j;
		size = strlen(grid[0]);
		for (i=1; i<size; i++)
		{
			cin >> grid[i];
		}
		visited = new int*[size];
		blob_size = 0;
		for (i=0; i<size; i++)
		{
			visited[i] = new int[size];
			for (j=0; j<size; j++)
			{
				visited[i][j] = false;
			}
		}
		int max_size = 0;
		for (i=0; i<size; i++)
		{
			for (j=0; j<size; j++)
			{
				if (!visited[i][j] && grid[i][j] == '1')
				{
					blob_size = 0;
					MaxBlob(i, j, size);
					if (blob_size > max_size)
					{
						max_size = blob_size;
					}
				}
			}
		}
		cout << max_size << endl;
		if (cases > 1)
		{
			cout << endl;
		}
		
		cases--;
	}
	
	return 0;
}