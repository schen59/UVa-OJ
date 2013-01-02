#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

struct node
{
	int r;
	int c;
	int path;
	bool visited;
};


int KnightMoves(int m, int n, int p, int q)
{
	queue<node> s;
	node nodes[8][8];
    int i, j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			nodes[i][j].r = i;
			nodes[i][j].c = j;
			nodes[i][j].path = INT_MAX;
			nodes[i][j].visited = false;
		}
	}
	nodes[m][n].path = 0;
	s.push(nodes[m][n]);
	while (!s.empty())
	{
		node cur_node = s.front();
		s.pop();
		int u = cur_node.r;
		int v = cur_node.c;
		nodes[u][v].visited = true;
		//cout << u << " " << v << " " << nodes[u][v].path << endl;
		if (u == p && v == q)
		{
			return nodes[u][v].path;
		}
		for (i=-2; i<3; i++)
		{
			if (i == 0)
			{
				continue;
			}
			j = 3 - abs(i);
			if (u+i>=0 && u+i<8 && v+j>=0 && v+j<8 && !nodes[u+i][v+j].visited)
			{
				nodes[u+i][v+j].visited = true;
				nodes[u+i][v+j].path = 1 + nodes[u][v].path;
				s.push(nodes[u+i][v+j]);
			}
			j = abs(i) - 3;
		    if (u+i>=0 && u+i<8 && v+j>=0 && v+j<8 && !nodes[u+i][v+j].visited)
			{
				nodes[u+i][v+j].visited = true;
				nodes[u+i][v+j].path = 1 + nodes[u][v].path;
				s.push(nodes[u+i][v+j]);
			}
		}
	}
}

int main()
{	
	int i, j, m, n;
	string ss, tt;
	while (cin >> ss >> tt)
	{
		i = ss[1] - '1';
		j = ss[0] - 'a';
		m = tt[1] - '1';
		n = tt[0] - 'a';
		cout << "To get from " << ss << " to " << tt << " takes " << KnightMoves(i, j, m, n) << " knight moves." << endl;
	}
	return 0;
}