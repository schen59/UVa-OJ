#include <iostream>
#include <string>
#include <cstdio> 
#include <cstring>
#include <algorithm>
using namespace std;

int min(int a, int b)
{
	return a<b ? a : b;
}

int word2num(string word)
{
	string::iterator it = word.begin();
	int num = 0;
	while (it != word.end())
	{
		num = (num<<5) + *it - 'a' + 1;
		it++;
	}
	return num;
}

int PerfectValue(int* W, int size)
{
	int n = size;
	int C_max = 1<<31;
	int C = W[0];
	//cout << C << endl;
	bool conflict = true;;
    while (conflict)
    {
		conflict = false;
		for (int i=0; i<n ; i++)
		{
			for (int j=i+1; j<n ; j++)
			{
				int w_1 = W[i];
				int w_2 = W[j];
				if ((C/w_1)%n == (C/w_2)%n)
				{
					C = min((C/w_1+1)*w_1, (C/w_2+1)*w_2);
					//cout << C << endl;
					conflict = true;
					if (C > C_max)
					{
						C_max = C;
					}
					//break;
				}
			}
			//if (conflict)
			//{
			//	break;
			//}
		}
		//cout << C << endl;
		if (conflict)
		{
			C = C_max;
		}
		
    }
	

	
	return C;
}

int main()
{
	char line[200];
	int W[30];
	char temp[30];
	int index = 0;

	while (gets(line))
	{
		index = 0;
		for (int j=0; j<30; j++)
		{
			W[j] =0;
		}
	    for(int i=0;i<strlen(line);i++)
            if(isalpha(line[i]))
            {
                sscanf(&line[i],"%s",temp);
                int p=strlen(temp);
                i+=p;
                for(int k=0;k<p;k++)
                    W[index]=(W[index]<<5)+(temp[k]-'a'+1);
                index++;
            }
		
		//cout << index << endl;
		sort(W, W+index);
		//for (int k=0; k<index; k++)
		//{
		//	cout << W[k] << " ";
		//}
		printf("%s\n", line);
		printf("%d\n", PerfectValue(W, index));
	    printf("\n");
	}
	
	
	
	return 0;
}