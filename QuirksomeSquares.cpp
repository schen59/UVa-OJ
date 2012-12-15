#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> qirk_num[4];

void QuirksomNumber(int digits)
{
	int max_num = 0;
	switch (digits)
	{
	case 1:
		max_num = 10;
		break;
	case 2:
		max_num = 100;
		break;
	case 3:
		max_num = 1000;
		break;
	case 4:
		max_num = 10000;
		break;
	default:
		break;
	}
	for (int i=0; i<max_num; i++)
	{
		for (int j=0; j<max_num; j++)
		{
			unsigned long result = (i+j) * (i+j);
			if (result == (i*max_num + j))
			{
				int k = 0;
				string str_result;
				stringstream ss;
				ss << result;
				str_result = ss.str();
				for (k=2*digits-str_result.length(); k>0; k--)
				{
					str_result = string("0") + str_result;
				}
				qirk_num[digits-1].push_back(str_result);
			}
		}
	}
}

int main()
{
	int digits = 0;
	for (int i=1; i<=4; i++)
	{
		QuirksomNumber(i);
	}
	while (cin >> digits)
	{
		for (vector<string>::iterator it=qirk_num[digits/2 -1].begin(); it!=qirk_num[digits/2 - 1].end(); it++)
		{
			cout << *it << endl;
		}
	}
	return 0;
}