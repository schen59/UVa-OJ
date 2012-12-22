#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

enum relation {A_EQ_B, A_GT_B, B_GT_A, A_NE_B, A_PE_B};

relation CompareSets(set<int>& set_a, set<int>& set_b)
{
	bool a_in_b = true;
	bool b_in_a = true;
	int a_count = 0;
	int b_count = 0;
	for (set<int>::iterator it_a=set_a.begin(); it_a!=set_a.end(); it_a++)
	{
		int elem_a = *it_a;
		if (set_b.find(elem_a) == set_b.end())
		{
			a_in_b = false;
		}
		else
		{
			a_count++;
		}
	}
	for (set<int>::iterator it_b=set_b.begin(); it_b!=set_b.end(); it_b++)
	{
		int elem_b = *it_b;
		if (set_a.find(elem_b) == set_a.end())
		{
			b_in_a = false;
		}
		else
		{
			b_count++;
		}
	}
	if (a_in_b && b_in_a)
	{
		return A_EQ_B;
	}
	else if (a_in_b)
	{
		return B_GT_A;
	}
	else if (b_in_a)
	{
		return A_GT_B;
	}
	else if (a_count>0 || b_count>0)
	{
		return A_PE_B;
	}
	else
	{
		return A_NE_B;
	}
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		stringstream ss;
		set<int> set_a;
		set<int> set_b;
		ss << line;
		int number = 0;
		while (ss >> number)
		{
			set_a.insert(number);
		}
		getline(cin, line);
		ss.clear();
		ss << line;
		while (ss >> number)
		{
			set_b.insert(number);
		}
		switch(CompareSets(set_a, set_b))
		{
		case A_EQ_B:
			cout << "A equals B" << endl;
			break;
		case A_GT_B:
			cout << "B is a proper subset of A" << endl;
			break;
		case B_GT_A:
			cout << "A is a proper subset of B" << endl;
			break;
		case A_PE_B:
			cout << "I'm confused!" << endl;
			break;
		case A_NE_B:
			cout << "A and B are disjoint" << endl;
			break;
		}
	}
	return 0;
}