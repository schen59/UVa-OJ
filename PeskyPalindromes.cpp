#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, bool> palindrome;

bool is_unique_palin(string sub_str)
{
	int i = 0;
	int j = sub_str.length()-1;
	while (i < j)
	{
		if (sub_str[i] == sub_str[j])
		{
			i++;
			j--;
		}
		else
		{
			return false;
		}
	}
	if (palindrome[sub_str] == true)
	{
		return false;
	}
	else
	{
		palindrome[sub_str] = true;
		return true;
	}
}

int main()
{
	string input;
	while (cin >> input)
	{
		palindrome.clear();
		int number = 0;
		for (int i=1; i<=input.length(); i++)
		{
			for (int j=0; j+i<=input.length(); j++)
			{
				string sub_str = input.substr(j, i);
				//cout << sub_str << endl;
				if (is_unique_palin(sub_str))
				{
					//cout << sub_str << endl;
					number++;
				}
			}
		}
		cout << "The string " << "'" << input << "' contains " << number << " palindromes." << endl; 
	}
	return 0;
}