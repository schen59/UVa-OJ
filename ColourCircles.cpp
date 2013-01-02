#include <iostream>
#include <queue>
#include <list>
#include <set>
using namespace std;
bool** visited = 0;

struct edge
{
	int adj_vex;
	int colour;
};

struct circle
{
	int vex_no;
	int colour;
	bool counter;
	list<edge> edges;
};

struct state
{
	int R;
	int S;
};

//void copyState(state& s_1, state& s_2)
//{
//	s_1.circles = (circle*)malloc(sizeof(s_2.circles));
//	memcpy(s_1.circles, &s_2.circles, sizeof(s_2.circles));
//	s_1.R = s_2.R;
//	s_1.S = s_2.S;
//}
int main()
{
	int N = 0;
	int R = 0;
	int S = 0;
	int T = 0;
	int M = 0;
	while (cin>>N>>R>>S>>T>>M && N>0)
	{
		//set<state> visited;
		visited = new bool*[N+1];
		vector<circle> circles;
		int i, j;
		circles.push_back(*new circle());
		for (i=1; i<=N; i++)
		{
			visited[i] = new bool[N+1];
			for (j=1; j<=N; j++)
			{
				visited[i][j] = false;
			}
			circle cir;
			cir.vex_no = i;
			cir.counter = false;
			cin >> cir.colour;
			circles.push_back(cir);
		}
		for (i=1; i<=M; i++)
		{
			int s,t,c;
			cin >> s >> t >> c;
			edge e;
			e.adj_vex = t;
			e.colour = c;
			circles[s].edges.push_back(e);
		}
		circles[R].counter = true;
		circles[S].counter = true;
		queue<state> q;
		list<edge>::iterator it;
		state s_0;
		s_0.R = R;
		s_0.S = S;
		q.push(s_0);
	
		queue<int> q_step;
		q_step.push(0);
		//cout << "computing" << endl;
		bool flag = false;
		while (!q.empty())
		{
			state s = q.front();
			//visited.insert(s);
			visited[s.R][s.S] = true;
			int step = q_step.front();
			q.pop();
			q_step.pop();
			//cout << s.R << " " << s.S << endl;
			if (s.R == T || s.S == T)
			{
				flag = true;
				cout << step << endl;
				break;
			}
			list<edge>::iterator it;
			for (it=circles[s.R].edges.begin(); it!=circles[s.R].edges.end(); it++)
			{
				edge e_1 = *it;
				int adj_vex_1 = e_1.adj_vex;
				int colour_1 = e_1.colour;
				state s_1;
				s_1.R = s.R;
				s_1.S = s.S;
				s_1.R = adj_vex_1;
				if (adj_vex_1!=s.S && colour_1==circles[s.S].colour && !visited[s_1.R][s_1.S])
				{	
					
					q.push(s_1);
					q_step.push(step+1);
				}
			}
			for (it=circles[s.S].edges.begin(); it!=circles[s.S].edges.end(); it++)
			{
				edge e_2 = *it;
				int adj_vex_2 = e_2.adj_vex;
				int colour_2 = e_2.colour;
				state s_2;
				s_2.R = s.R;
				s_2.S = s.S;
				s_2.S = adj_vex_2;
				if (adj_vex_2!=s.R && colour_2==circles[s.R].colour && !visited[s_2.R][s_2.S])
				{
					
					q.push(s_2);
					q_step.push(step+1);
				}
			}
		}
		if (!flag)
		{
			cout << 0 << endl;
		}
		//cout << "end computing" << endl;
	}
	return 0;
}