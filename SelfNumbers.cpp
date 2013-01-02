#include <iostream>
using namespace std;

int main()
{
	bool self_number[1000001];
	int i;
	for (i=0; i<1000001; i++)
	{
		self_number[i] = false;
	}
	for (i=0; i<1000001; i++)
	{
		int sum = i;
		int temp = i;
		while (temp > 0)
		{
			sum += temp%10;
			temp /= 10;
		}
		if (sum < 1000001)
		{
			self_number[sum] = 1;
		}
	}
	for (int j=0; j<1000001; j++)
	{
		if (self_number[j] == false)
		{
			cout << j << endl;
		}
	}
	return 0;
}