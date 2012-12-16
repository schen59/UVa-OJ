#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

int NextNumber(int number)
{
	stringstream ss;
	ss << number;
	string str_num = ss.str();
	sort(str_num.begin(), str_num.end());
	string str_num_2 = str_num;
	reverse(str_num_2.begin(), str_num_2.end());
	int first = 0;
	stringstream(str_num_2) >> first;
	int second = 0;
	stringstream(str_num) >> second;
	int result = first - second;
	cout << first << " - " << second << " = " << result << endl;
    return result;
}

int main()
{
	int number = 0;
	cin >> number;
	while (number != 0)
	{
		cout << "Original number was " << number << endl;
		int result = NextNumber(number); 
		map<int, bool> chain;
		int chain_length = 1;
		while (chain[result] == false)
		{
			chain[result] = true;
			result = NextNumber(result);
			chain_length++;
		}
		cout << "Chain length " << chain_length << endl;
		cout << endl;
		cin >> number;
	}
	return 0;
}