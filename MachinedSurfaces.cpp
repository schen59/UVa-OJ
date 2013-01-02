#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int N = 0;
	cin >> N;
	while (N > 0)
	{
		string line;
		int min_spaces = 3200;
		int total_spaces = 0;
		int line_spaces = 0;
		getline(cin, line);
		for (int i=0; i<N; i++)
		{
			getline(cin, line);
			cout << line << endl;
			line_spaces = 0;
			for (int j=0; j<line.length(); j++)
			{
				if (line[j] == ' ')
				{
					line_spaces++;
					total_spaces++;
				}
			}
			if (line_spaces < min_spaces)
			{
				min_spaces = line_spaces;
			}
		}
		cout << total_spaces - N*min_spaces << endl;
		cin >> N;
	}
	return 0;
}