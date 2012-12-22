#include <iostream>
#include <list>
using namespace std;

int Joseph(int k)
{
	int m = k+1;
	int killed_num = 0;
	while (1)
	{
		killed_num = 0;
		list<int> alived;
		for (int i=1; i<=2*k; i++)
		{
			alived.push_back(i);
		}
		//for (list<int>::iterator it=alived.begin(); it!=alived.end(); it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;
		while (!alived.empty())
		{
			cout << m << endl;
			for (int j=0; j<m-1; j++)
			{
				alived.push_back(alived.front());
				alived.pop_front();
			}
			int killed = alived.front();
			//cout << m << " " << killed << endl;
			alived.pop_front();
			if (killed > k)
			{
				killed_num++;
				if (killed_num == k)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		if (killed_num == k)
		{
			break;
		}
		else
		{
			m++;
		}
	}
	return m;
}

int main()
{
	int k = 0;
	int Val[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
	cin >> k;
	while (k > 0)
	{
		cout << Val[k] << endl;
		cin >> k;
	}
	return 0;
}