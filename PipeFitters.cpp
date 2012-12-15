#include <iostream>
#include <cmath>
using namespace std;

int Grid(double width, double height)
{
	return (int)floor(width) * (int)floor(height);
}

int Skew(double width, double height)
{
    double delta = sqrt(3) / 2;
	int rc_1 = 0;
	int rc_2 = 0;
    double tmp  = 0;
	while (tmp+1 <= width)
	{
		rc_1++;
		tmp++;
	}
	tmp = 0.5;
	while (tmp+1 <= width)
	{
		rc_2++;
		tmp++;
	}
	int capacity = 0;
	bool flag = true;
	double h = 0;
	while (h+1 < height)
	{
		if (flag)
		{
			capacity += rc_1;
		}
		else
		{
			capacity += rc_2;
		}
		flag = !flag;
		h += delta;
	}
	return capacity;
}

int main()
{
	double width  = 0;
	double height = 0;
    while (cin >> width >> height)
    {
		int grid = Grid(width, height);
		int skew_1 = Skew(width, height);
		int skew_2 = Skew(height, width);
		int skew = skew_1 > skew_2 ? skew_1 : skew_2;
		if (grid >= skew)
		{
			cout << grid << " " << "grid" << endl;
		}
		else
		{
			cout << skew << " " << "skew" << endl;
		}
    }
	return 0;
}