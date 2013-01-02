#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct square
{
	double x_1;
	double y_1;
	double x_2;
	double y_2;
};

bool isCovered(square s, square* squares, int n)
{
	for (int i=0; i<n; i++)
	{
		double x_1 = squares[i].x_1;
		double y_1 = squares[i].y_1;
		double x_2 = squares[i].x_2;
		double y_2 = squares[i].y_2;
		if (s.x_1>=x_1 && s.x_2<=x_2 && s.y_1>=y_1 && s.y_2<=y_2)
		{
			return true;
		}
	}
	return false;
}

double Coverage(double* h, double* v, square* squares, int n)
{
	bool** grid = new bool*[2*n-1];
	int i, j;
	for (i=0; i<2*n-1; i++)
	{
		grid[i] = new bool[2*n-1];
		for (j=0; j<2*n-1; j++)
		{
			grid[i][j] = false;
		}
	}
	sort(h, h+2*n);
	sort(v, v+2*n);
	double area = 0;
	for (i=0; i<2*n-1; i++)
	{
		for (j=0; j<2*n-1; j++)
		{
			square s;
			s.x_1 = h[i];
			s.y_1 = v[j];
			s.x_2 = h[i+1];
			s.y_2 = v[j+1];
			//cout << s.x_1 << " " << s.y_1 << " " << s.x_2 << " " << s.y_2 << endl;
			if (isCovered(s, squares, n))
			{
				grid[i][j] = true;
				area += (s.x_2-s.x_1) * (s.y_2-s.y_1);
			}
			//cout << i << " " << j << " " << grid[i][j] << endl;
		}
	}
	return area;
}
int main()
{
	int n = 0;
	int case_no = 1;
	while (cin>>n && n>0)
	{
		double* h = new double[2*n];
		double* v = new double[2*n];
		square* squares = new square[n];
		double x, y, r;
		for (int i=0; i<n; i++)
		{
			cin >> x >> y >> r;
			h[2*i] = x-r;
			h[2*i+1] = x+r;
			v[2*i] = y-r;
			v[2*i+1] = y+r;
			squares[i].x_1 = x-r;
			squares[i].y_1 = y-r;
			squares[i].x_2 = x+r;
			squares[i].y_2 = y+r;
		}
		cout << case_no++ << " ";
		cout << fixed << setprecision(2) << Coverage(h, v, squares, n) << endl;
	}
	return 0;
}