#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.141592653589793
using namespace std;

int main()
{
	double x_1, y_1;
	double x_2, y_2;
	double x_3, y_3;
	while (cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3)
	{
		double s_1 = sqrt(pow(x_1-x_2, 2) + pow(y_1-y_2, 2));
		double s_2 = sqrt(pow(x_1-x_3, 2) + pow(y_1-y_3, 2));
		double s_3 = sqrt(pow(x_2-x_3, 2) + pow(y_2-y_3, 2));
		double s   = (s_1+s_2+s_3) / 2;
		double area = sqrt(s * (s-s_1) * (s-s_2) * (s-s_3));
		double r = (s_1*s_2*s_3) / (4*area);
		cout << fixed;
		cout << setprecision(2) << 2*PI*r << endl;
	}
	return 0;
}