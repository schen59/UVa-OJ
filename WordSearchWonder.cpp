#include <iostream>
#include <utility>
#include <string>
using namespace std;

void Search(char** letter_mat, int size, string word)
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			if (letter_mat[i][j] == word[0])
			{
				for (int dx=-1; dx<=1; dx++)
				{
					for (int dy=-1; dy<=1; dy++)
					{
						if (dx==0 && dy==0)
						{
							continue;
						}
						int count = 0;
						for (int k=0; k<word.length(); k++)
						{
							int u = i + dy*k;
							int v = j + dx*k;
							if (u>=size || v>=size || u<0 || v<0)
							{
								break;
							}
							if (word[k] == letter_mat[u][v])
							{
								count++;
								if (count == word.length())
								{
									cout << i+1 << "," << j+1 << " " << u+1 << "," << v+1 << endl;
									return;
								}
							}
							else
							{
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << "Not found" << endl;
	return;
}

int main()
{
	int l = 0;
	cin >> l;
	char** letter_mat = new char*[l];
	for (int i=0; i<l; i++)
	{
		letter_mat[i] = new char[l];
		cin >> letter_mat[i];
	}
	string word;
	cin >> word;
	while (word.compare("0") != 0)
	{

		Search(letter_mat, l, word);
		
		cin >> word;
	}
	return 0;
}