#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n = 0;
	double p = 0;
	while (cin >> n)
	{
		cin >> p;
		cout.setf(ios::fixed);
		cout.precision(0);
		cout << pow(p, 1.0/n) << endl;
	}
	return 0;
}