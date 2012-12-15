#include <iostream>
#include <string>
using namespace std;

bool Anagram(string s_1, string s_2)
{
	if (s_1=="" || s_2=="")
	{
		return false;
	}
	if (s_1.length() != s_2.length())
	{
		return false;
	}
	int frequency[26];
	for (int i=0; i<26; i++)
	{
		frequency[i] = 0;
	}
	string::iterator it = s_1.begin();
	while (it != s_1.end())
	{
		frequency[tolower(*it) - 'a']++;
		it++;
	}
	it = s_2.begin();
	while (it != s_2.end())
	{
		frequency[towlower(*it) - 'a']--;
		it++;
	}
	for (int j=0; j<26; j++)
	{
		if (frequency[j])
		{
			return false;
		}
	}
	return true;
}

void Sort(string* ananagrams, int number)
{
	for (int i=0; i<number; i++)
	{
		for (int j=i+1; j<number; j++)
		{
			if (ananagrams[i].compare(ananagrams[j]) > 0)
			{
				string tmp = ananagrams[i];
				ananagrams[i] = ananagrams[j];
				ananagrams[j] = tmp;
			}
		}
	}
}

int main()
{
	string dictionary[1000];
    string s;
	int dic_size = 0;
	cin >> s;
	while (s.compare("#") != 0)
	{
		dictionary[dic_size] = s;
		dic_size++;
		cin >> s;
	}
    bool* is_ananagram = new bool[dic_size];
	int i, j;
	for (i=0; i<dic_size; i++)
	{
		is_ananagram[i] = true;
	}
	for (i=0; i<dic_size; i++)
	{
		for (j=i+1; j<dic_size; j++)
		{
			if (Anagram(dictionary[i], dictionary[j]))
			{
				is_ananagram[i] = false;
				is_ananagram[j] = false;
			}
		}
	}
	int ananagram_num = 0;
	for (i=0; i<dic_size; i++)
	{
		if (is_ananagram[i])
		{
			ananagram_num++;
		}
	}
	string* ananagrams = new string[ananagram_num];
	int index = 0;
	for (i=0; i<dic_size; i++)
	{
		if (is_ananagram[i])
		{
			ananagrams[index++] = dictionary[i];
		}
	}
	Sort(ananagrams, ananagram_num);
	for (i=0; i<ananagram_num; i++)
	{
		cout << ananagrams[i] << endl;
	}
	return 0;
}