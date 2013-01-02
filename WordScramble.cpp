#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		stringstream ss;
		ss << line;
		string word;
		ss >> word;
		int i;
        for (i=word.length()-1; i>=0; i--)
		{
			cout << word[i];
		}
		while (ss >> word)
		{
			//cout << word << " ";
			cout << " ";
			for (i=word.length()-1; i>=0; i--)
			{
				cout << word[i];
			}
		}
		cout << endl;
	}
	return 0;
}