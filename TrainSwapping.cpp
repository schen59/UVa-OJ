#include <iostream>
using namespace std;

int Count(int* carriage, int size)
{
	int count = 0;
	for (int i=0; i<size; i++)
	{
		for (int j=i+1; j<size; j++)
		{
			if (carriage[i] > carriage[j])
			{
				int temp    = carriage[i];
				carriage[i] = carriage[j];
				carriage[j] = temp;
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int N = 0;
	int L = 0;
	int* carriage = 0;
	cin >> N;
	for (int i=0; i<N; i++)
	{
		cin >> L;
		carriage = new int[L];
		for (int j=0; j<L; j++)
		{
			cin >> carriage[j];
		}
		cout << "Optimal train swapping takes " << Count(carriage, L) << " swaps." << endl;
		delete[] carriage;
		carriage = 0;
	}
	return 0;
}