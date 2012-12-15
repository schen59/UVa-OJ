#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string anagram;
bool* visited;
string result;

int cmp(char a, char b)
{
	int diff = towlower(a) - tolower(b);
	return diff ? diff<0 : a<b;
}

void Permutation(int i, int length)
{
	if (i == length)
	{
		cout << result << endl;
	}
	else
	{
		for (int j=0; j<length; j++)
		{
			if (!visited[j])
			{
				if (j>0 && anagram[j] == anagram[j-1] && !visited[j-1])
				{
					continue;
				}
				visited[j] = true;
				result[i] = anagram[j];
				Permutation(i+1, length);
				visited[j] = false;
			}
		}
	}
}

int main()
{
	int words_num = 0;
	cin >> words_num;
	for (int i=0; i<words_num; i++)
	{
		cin >> anagram;
		result = anagram;
		int length = anagram.length();
		visited = new bool[length];
		for (int j=0; j<length; j++)
		{
			visited[j] = false;
		}
		sort(anagram.begin(), anagram.end(), cmp);
		Permutation(0, length);
	}
	return 0;
}