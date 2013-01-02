#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int r;
	int c;
	char type;
	bool visited;
};

void OilDeposits(node** nodes, int r, int c, int rows, int cols)
{
	queue<node> q;
	nodes[r][c].visited = true;
	q.push(nodes[r][c]);
	while (!q.empty())
	{
		node cur_node = q.front();
		q.pop();
		int m = cur_node.r;
		int n = cur_node.c;
		for (int i=-1; i<=1; i++)
		{
			for (int j=-1; j<=1; j++)
			{
				if (i==0 && j==0)
				{
					continue;
				}
				if (m+i>=0 && m+i<rows && n+j>=0 && n+j<cols && !nodes[m+i][n+j].visited && nodes[m+i][n+j].type=='@')
				{
					nodes[m+i][n+j].visited = true;
					q.push(nodes[m+i][n+j]);
				}
			}
		}
	}
}

int main()
{
	int rows = 0;
	int cols = 0;
	int i, j;
	cin >> rows >> cols;
	while (rows>0 && cols>0)
	{
		node** nodes = new node*[rows];
		for (i=0; i<rows; i++)
		{
			nodes[i] = new node[cols];
			for (j=0; j<cols; j++)
			{
				nodes[i][j].r = i;
				nodes[i][j].c = j;
				cin >> nodes[i][j].type;
				nodes[i][j].visited = false;
			}
		}
		int num = 0;
		for (i=0; i<rows; i++)
		{
			for (j=0; j<cols; j++)
			{
				if (!nodes[i][j].visited && nodes[i][j].type=='@')
				{
					OilDeposits(nodes, i, j, rows, cols);
					num++;
				}
			}
		}
		cout << num << endl;
		for (i=0; i<rows; i++)
		{
			delete[] nodes[i];
		}
		delete[] nodes;
		nodes = 0;
		cin >> rows >> cols;
	}
	return 0;
}