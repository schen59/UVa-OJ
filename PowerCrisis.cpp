#include <iostream>
#include <list>
using namespace std;

int LastRegion(int region_num, int m)
{
	list<int> power_on_region;
	for (int i=1; i<=region_num; i++)
	{
		power_on_region.push_back(i);
	}
	while (power_on_region.size() > 1)
	{
		power_on_region.pop_front();
		for (int j=1; j<m; j++)
		{
			power_on_region.push_back(power_on_region.front());
			power_on_region.pop_front();
		}

	}
	return power_on_region.front();
}

int main()
{
	int region_num = 13;
	int m = 1;
	cin >> region_num;
	while (region_num > 0)
	{
		m = 1;
		while (1)
		{
			int last_region = LastRegion(region_num, m);
			if (last_region == 13)
			{
				break;
			}
		    m++;
		}
		cout << m << endl;
		cin >> region_num;
	}
	return 0;
}