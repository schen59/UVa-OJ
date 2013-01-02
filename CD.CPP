#include <iostream>
#include <stack>
using namespace std;

int max(int a, int b)
{
	return a<b ? b : a;
}

void MaxCD(int N, int T, int* W)
{
	int i, j;
	int** B = new int*[T+1];
	int** P = new int*[T+1];
 	for (i=0; i<=T; i++)
	{
		P[i] = new int[N+1];
		B[i] = new int[N+1];
		for (j=0; j<=N; j++)
		{
			P[i][j] = -1;
		}
	}
	for (i=0; i<=N; i++)
	{
		B[0][i] = 0;
	}
	for (i=1; i<=T; i++)
	{
		for (j=0; j<=N; j++)
		{
			if (j >= W[i])
			{
				B[i][j] = max(B[i-1][j], B[i-1][j-W[i]]+W[i]);
				if (B[i-1][j-W[i]]+W[i] > B[i-1][j])
				{
					P[i][j] = 1;
				}
			}
			else
			{
				B[i][j] = B[i-1][j];
			}
		}
	}
	int item = T;
	int size = N;
	stack<int> s;
	while (item > 0)
	{
		if (P[item][size] == 1)
		{
			//cout << item << " " << size << " ";
			//cout << W[item] << " ";
			s.push(W[item]);
			size -= W[item];
			item--;
			
		}
		else
		{
			item--;
		}
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "sum:" << B[T][N] << endl;
}

int main()
{
	int N = 0;
	int T = 0;
	int *W = 0;
	while (cin >> N)
	{
		cin >> T;
		W = new int[T+1];
		for (int i=1; i<=T; i++)
		{
			cin >> W[i];
		}
		MaxCD(N, T, W);
		
	}
	
	return 0;
}