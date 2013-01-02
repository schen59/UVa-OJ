#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string end = "XXXXXX";
	string dict[101];
	int dict_size = 0;
	string word;
	while (cin >> word && word!=end)
	{
		dict[dict_size++] = word;
	}
	sort(dict, dict+dict_size);
	while (cin >> word && word!=end)
	{
		sort(word.begin(), word.end());
		bool flag = false;
		for (int i=0; i<dict_size; i++)
		{
			string temp = dict[i];
			if (temp.length() != word.length())
			{
				continue;
			}
			sort(temp.begin(), temp.end());
			if (temp == word)
			{
				cout << dict[i] << endl;
				flag = true;
			}
		}
		if (!flag)
		{
			cout << "NOT A VALID WORD" << endl;
		}
		cout << "******" << endl;
	}
	return 0;
}