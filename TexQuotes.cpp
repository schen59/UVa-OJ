#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	int quote_idx = 0;
	while (getline(cin, text))
	{
		if (cin.eof())
		{
			break;
		}
		for (int i=0; i<text.length(); i++)
		{
			if (text[i] == '"')
			{
				++quote_idx;
				quote_idx%2 == 0 ? cout << "''" : cout << "``";
			}
			else
			{
				cout << text[i];
			}
		}
		cout << endl;
	}
	return 0;
}