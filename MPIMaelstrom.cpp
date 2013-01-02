#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <climits>
using namespace std;

struct node
{
	int name;
	int cost;
	bool operator<(const node& next) const
	{
		if (cost != next.cost)
		{
			return cost > next.cost;
		}
		if (name != next.name)
		{
			return name > next.name;
		}
		return false;
	}
};

int Dijkstra(int** costs, int size, int s)
{
	priority_queue<node> pq;
	bool* visited = new bool[size];
	int * dist = new int[size];
	for (int i=0; i<size; i++)
	{
		visited[i] = false;
		dist[i] = INT_MAX;
	}
	dist[s] = 0;
	node n_s;
	n_s.name = s;
	n_s.cost = 0;
	pq.push(n_s);
	while (!pq.empty())
	{
		node cur_node = pq.top();
		pq.pop();
		int u = cur_node.name;
		visited[u] = true;
		for (int v=0; v<size; v++)
		{
			if (!visited[v] && costs[u][v]<INT_MAX)
			{
				if (dist[u]+costs[u][v] < dist[v])
				{
					dist[v] = dist[u] + costs[u][v];
					node new_node;
					new_node.name = v;
					new_node.cost = dist[v];
					pq.push(new_node);
				}
			}
		}
	}
	int max_time = -1;
	for (int j=0; j<size; j++)
	{
		if (dist[j] > max_time)
		{
			max_time = dist[j];
		}
	}
	delete[] visited;
	delete[] dist;
	visited = 0;
	dist = 0;
	return max_time;
}

int main()
{
	int n = 0;
	string cost;
	cin >> n;
	int** costs = new int*[n];
	int i, j;
	for (i=0; i<n; i++)
	{
		costs[i] = new int[n];
		costs[i][i] = 0;
		for (j=0; j<i; j++)
		{
			stringstream ss;
			cin >> cost;
			if (cost.compare("x") == 0)
			{
				costs[j][i] = costs[i][j] = INT_MAX;
			}
			else
			{
				ss << cost;
				ss >> costs[j][i];
				costs[i][j] = costs[j][i];
			}
		}
	}
	cout << Dijkstra(costs, n, 0) << endl;
	for (i=0; i<n; i++)
	{
		delete[] costs[i];
	}
	delete[] costs;
	costs = 0;
	return 0;
}