#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	char line[2000];
	while (gets(line))
	{
		int word_num = 0;
		int i = 0;
		int length = strlen(line);
		while (i < length)
		{
			while (!isalpha(line[i]))
			{
				i++;
			}
			if (i < length)
			{
				word_num++;
			}
			while (isalpha(line[i]))
			{
				i++;
			}
		}
		cout << word_num << endl;
	}
	return 0;
}