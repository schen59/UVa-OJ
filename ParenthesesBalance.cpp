#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	string line;
	getline(cin, line);
	for (int i=0; i<n; i++)
	{
		getline(cin, line);
		stack<char> s;
		bool balance = true;
		for (int j=0; j<line.length(); j++)
		{
			if (line[j]=='(' || line[j]=='[')
			{
				s.push(line[j]);
			}
			else
			{
				if (s.empty())
				{
					balance = false;
					break;
				}
				char t = s.top();
				s.pop();
				if ((line[j]==')' && t=='[') || (line[j]==']' && t=='('))
				{
					balance = false;
					break;
				}
			}
		}
		if (!balance || !s.empty())
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}