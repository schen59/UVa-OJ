#include <iostream>
using namespace std;

bool* visited = 0;
enum color {white, gray, black};
color* v_color = 0;

void DFS(bool** is_reachable, int v_num, int s)
{
	v_color[s] = gray;
	for (int i=0; i<v_num; i++)
	{
		if (is_reachable[s][i])
		{
			visited[i] = true;
			if (v_color[i] == white)
			{
				DFS(is_reachable, v_num, i);
			}
		}
	}
	v_color[s] = black;
}

int main()
{
	bool** is_reachable = 0;
	int v_num = 0;
	int i = 0;
	int j = 0;
	cin >> v_num;
	while (v_num > 0)
	{
		visited = new bool[v_num];
		v_color = new color[v_num];
		is_reachable = new bool*[v_num];
		for (i=0; i<v_num; i++)
		{
			is_reachable[i] = new bool[v_num];
			for (j=0; j<v_num; j++)
			{
				is_reachable[i][j] = false;
			}
		}
		int m = 0;
		int n = 0;
		cin >> m;
		while (m > 0)
		{
			cin >> n;
			while (n > 0)
			{
				is_reachable[m-1][n-1] = true;
				cin >> n;
			}
			cin >> m;
		}
		int start = 0;
		int s_num = 0;
		cin >> s_num;
		for (i=0; i<s_num; i++)
		{
			cin >> start;
			for (j=0; j<v_num; j++)
			{
				visited[j] = false;
				v_color[j] = white;
			}
			DFS(is_reachable, v_num, start-1);
			int inaccess_num = 0;
			for (j=0; j<v_num; j++)
			{
				if (!visited[j])
				{
					inaccess_num++;
				}
			}
			cout << inaccess_num;
			for (j=0; j<v_num; j++)
			{
				if (!visited[j])
				{
					cout << " " << j+1;
				}
			}
			cout << endl;
		}
		
		for (i=0; i<v_num; i++)
		{
			delete[] is_reachable[i];
		}
		delete[] is_reachable;
		delete[] visited;
		delete[] v_color;
		visited = 0;
		v_color = 0;
		is_reachable = 0;
		cin >> v_num;
	}
	return 0;
}