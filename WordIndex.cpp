#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

map<string, int> idx_map;
int idx = 1;

void MapDFS(string word, int size)
{
	if (word.length() == size)
	{
		idx_map[word] = idx;
		idx++;
		return;
	}
	char last = 'a';
	if (word.length() > 0)
	{
		last = word[word.length() - 1] + 1;
	}
	for (char i=last; i<='z'; i++)
	{
		stringstream ss;
		ss << word << i;
		MapDFS(ss.str(), size);
	}
}

int main()
{
	for (int letter_num=1; letter_num<=5; letter_num++)
	{
		MapDFS("", letter_num);
	}
	string word;
	while (cin >> word)
	{
		//string sorted = word;
		//sort(sorted.begin(), sorted.end());
		//if (word.compare(sorted) != 0)
		//{
		//	cout << 0 << endl;
		//	continue;
		//}
		cout << idx_map[word] << endl;
	}
	return 0;
}