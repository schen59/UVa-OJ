#include <iostream>
#include <iomanip>
using namespace std;

int TrailingZero(int N)
{
	int count = 0;
	for (int i=5; N/i>0; i*=5)
	{
		count += N/i;
	}
	return count;
}

int LastNonZeroDigit(int N)
{
	int digit = 1;
	for (int i=1; i<=N; i++)
	{
		digit *= i;
		while (digit%10 == 0)
		{
			digit /= 10;
		}
		digit = digit%100000;
	}
	digit = digit % 10;
	return digit;
}
int main()
{
	int N = 0;
	while (cin >> N)
	{
		int digit = 0;
		digit = LastNonZeroDigit(N);
		cout << right << setw(5) << N << " -> " << digit << endl;
	}
	return 0;
}