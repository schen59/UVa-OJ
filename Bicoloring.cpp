#include <iostream>
#include <stack>
using namespace std;

enum color {white, black};

bool Bicoloring(bool** edges, int n)
{
	bool* visited = new bool[n];
	color* node_color = new color[n];
	stack<int> s;
	stack<int> length;
	for (int i=0; i<n; i++)
	{
		visited[i] = false;
	}
	s.push(0);
	length.push(0);
	visited[0] = true;
	node_color[0] = white;
	while (!s.empty())
	{
		int u = s.top();
		int l = length.top();
		s.pop();
		length.pop();
		for (int v=0; v<n; v++)
		{
			if (edges[u][v])
			{
				if (visited[v])
				{
					if (node_color[u] == node_color[v])
					{
						return false;
					}
				}
				else
				{
					visited[v] = true;
					s.push(v);
					length.push(l+1);
					if ((l+1)%2 == 0)
					{
						node_color[v] = white;
					}
					else
					{
						node_color[v] = black;
					}
				}
			}
		}
	}
	delete[] visited;
	delete[] node_color;
	visited = 0;
	node_color = 0;
	return true;
}

int main()
{
	int n = 0;
	cin >> n;
	bool** edges = 0;
	while (n > 0)
	{
		edges = new bool*[n];
		int i = 0;
		int j = 0;
		for (i=0; i<n; i++)
		{
			edges[i] = new bool[n];
			for (j=0; j<n; j++)
			{
				edges[i][j] = false;
			}
		}
		int l = 0;
		cin >> l;
		for (i=0; i<l; i++)
		{
			int u = 0;
			int v = 0;
			cin >> u >> v;
			edges[u][v] = true;
		}
		if (Bicoloring(edges, n))
		{
			cout << "BICOLORABLE." << endl;
		}
		else
		{
			cout << "NOT BICOLORABLE." << endl;
		}
		for (i=0; i<n; i++)
		{
			delete[] edges[i];
		}
		delete[] edges;
		edges = 0;
		cin >> n;
	}
	return 0;
}