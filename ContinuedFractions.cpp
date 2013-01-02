#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int d = 0;
	while (cin >> n >> d)
	{
		cout << "[" << n/d << ";";
		do 
		{
			int temp = d;
			d = n - (n/d) * d;
			n = temp;
			if (n%d != 0)
			{
				cout << n/d << ",";
			}
			else
			{
				cout << n/d << "]" << endl;
			}
		} while (n%d != 0);
	}
	return 0;
}