#include <iostream>
#include <string>
using namespace std;

int main()
{
	string poem;
	while (getline(cin, poem) && poem.compare("e/o/i")!=0)
	{
		int line_no = 1;
		int syllables = 0;
		bool haiku = true;
		for (int i=0; i<poem.length(); i++)
		{
			bool flag  = false;
			while (poem[i]=='a' || poem[i]=='e' || poem[i]=='i' || poem[i]=='o' || poem[i]=='u' || poem[i]=='y')
			{
				i++;
				flag = true;
			}
			if (flag)
			{
				syllables++;
				i--;
			}
			if (poem[i] == '/')
			{
				if ((line_no==1) && syllables!=5)
				{
					cout << line_no << endl;
					haiku = false;
					break;
				}
				if (line_no==2 && syllables!=7)
				{
					cout << line_no << endl;
					haiku = false;
					break;
				}
				line_no++;
				syllables = 0;
			}
		}
		if (haiku)
		{
			if (line_no==3 && syllables!=5)
			{
				cout << line_no << endl;
			}
			else
			    cout << "Y" << endl;
		}
	}
	return 0;
}