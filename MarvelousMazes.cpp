#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	char line[150];
	while (gets(line))
	{
		int num = 0;
		for (int i=0; line[i]!=0; i++)
		{
			int j = 0;
			char c = line[i];
			if (c == '!')
			{
				cout << endl;
			}
			else if (c>='0' && c<='9')
			{
				num += c-'0';
			}
			else
			{
				for (int j=0; j<num; j++)
				{
					if (c == 'b')
					{
						cout << " ";
					}
					else
					{
						cout << c;
					}
				}
				num = 0;
			}
		}
		cout << endl;
	}
	return 0;
}