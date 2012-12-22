#include <iostream>
using namespace std;

void ComputeHartal(int days, int param, bool* is_hartal)
{
	for (int i=param; i<=days; i+=param)
	{
		if (i%7==6 || i%7==0)
		{
			continue;
		}
		is_hartal[i] = true;
	}
}

int main()
{
	int tests = 0;
	cin >> tests;
	bool* is_hartal = 0;
	for (int i=0; i<tests; i++)
	{
		int days    = 0;
		int hartals = 0;
		int param   = 0;
		cin >> days;
		is_hartal = new bool[days+1];
		int j = 0;
		for (j=0; j<=days; j++)
		{
			is_hartal[j] = false;
		}
		cin >> hartals;
		for (j=0; j<hartals; j++)
		{
			cin >> param;
			ComputeHartal(days, param, is_hartal);
		}
		int day_loss = 0;
		for (j=1; j<=days; j++)
		{
			if (is_hartal[j])
			{
				//cout << "1" << " ";
				day_loss++;
			}
			else
			{
				//cout << "0" << " ";
			}
		}
		cout << day_loss << endl;
		delete[] is_hartal;
		is_hartal = 0;
	}
	return 0;
}