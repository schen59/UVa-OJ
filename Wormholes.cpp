#include <iostream>
#include <climits>
using namespace std;

struct edge
{
	int u;
	int v;
	int t;
};

bool Wormholes(edge* costs, int n, int m)
{
	int* dist = new int[n];
	int i, j;
	for (i=0; i<n; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[0] = 0;
	for (i=1; i<=n-1; i++)
	{
		for (j=0; j<m; j++)
		{
			if (dist[costs[j].u] + costs[j].t < dist[costs[j].v])
			{
				dist[costs[j].v] = dist[costs[j].u] + costs[j].t;
			}
		}
	}
	for (j=0; j<m; j++)
	{
		if (dist[costs[j].u] + costs[j].t < dist[costs[j].v])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int c = 0;
	cin >> c;
	int i, j;
	for (i=0; i<c; i++)
	{
		int n = 0;
		int m = 0;
		cin >> n >> m;
		edge* costs = new edge[m];
		for (j=0; j<m; j++)
		{
			int u = 0;
			int v = 0;
			int t = 0;
			cin >> u >> v >> t;
			costs[j].u = u;
			costs[j].v = v;
			costs[j].t = t;
		}
		if (Wormholes(costs, n, m))
		{
			cout << "possible" << endl;
		}
		else
		{
			cout << "not possible" << endl;
		}
		delete[] costs;
	}
	return 0;
}