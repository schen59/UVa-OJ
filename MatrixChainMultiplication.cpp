#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct matrix
{
	int rows;
	int cols;
};
int main()
{
	int n = 0;
	matrix matrices[26];
	cin >> n;
	for (int i=0; i<n; i++)
	{
		char mat;
		int rows, cols;
		cin >> mat >> rows >> cols;
		matrices[mat-'A'].rows = rows;
		matrices[mat-'A'].cols = cols;
		//cout << mat << " " << matrices[mat-'A'].rows << " " << matrices[mat-'A'].cols << endl;
	}
	string expression;
	while (cin >> expression)
	{
		stack<matrix> s;
		if (expression.length() == 1)
		{
			cout << 0 << endl;
			continue;
		}
		int mutiplications = 0;
		bool flag = true;
		for (int j=0; j<expression.length(); j++)
		{
			char m = expression[j];
			if (m == ')')
			{
				matrix B = s.top();
				s.pop();
				matrix A = s.top();
				s.pop();
				if (A.cols != B.rows)
				{
					flag = false;
					break;
				}
				mutiplications += A.rows*A.cols*B.cols;
				matrix res = {A.rows, B.cols};
				s.push(res);
			}
			else if (m != '(')
			{
				s.push(matrices[m-'A']);
			}
		}
		if (flag)
		{
			cout << mutiplications << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	return 0;
}