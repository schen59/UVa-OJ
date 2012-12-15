#include <iostream>
using namespace std;

void CountOnCantor(int index)
{
	int diagonal = 0;
	int count = index;
	for (diagonal=1; diagonal<index; diagonal++)
	{
		index -= diagonal;
	}
	int d = 0;
	int n = 1;
	if (diagonal%2 == 0)
	{
		d = index;
	}
	else
	{
		d = diagonal - index + 1;
	}
	n = diagonal - d + 1;
	cout << "TERM " << count << " IS " << d << "/" << n << endl;
}
int main()
{
	int index = 0;
	while (cin >> index)
	{
		CountOnCantor(index);
	}
	return 0;
}