#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

double Degree(int HH, int MM)
{
	HH = HH % 12;
	double m_degree = 6*MM;
	double h_degree = 30*HH + 30*MM/60.0;
	return fabs(h_degree-m_degree)<180 ? fabs(h_degree-m_degree) : 360-fabs(h_degree-m_degree);
}

int main()
{
	string time;
	string hh;
	string mm;
	cin >> time;
	while (time.compare("0:00") != 0)
	{
		int idx = time.find(":");
		hh = time.substr(0, idx);
		mm = time.substr(idx+1);
		stringstream ss;
		ss << hh;
		int HH, MM;
		ss >> HH;
		ss.clear();
		ss << mm;
		ss >> MM;
		cout << fixed;
		cout << setprecision(3) << Degree(HH, MM) << endl;
		cin >> time;
	}
	return 0;
}