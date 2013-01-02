#include <iostream>
#include <string>
using namespace std;

int maxArea(string molecules[])
{
	int length = molecules[0].length();
	int i_1 = 0;
	int j_1 = 0;
	int i_2 = 0;
	int j_2 = 0;
	int i_3 = 0;
	int j_3 = 0;
	int i_4 = 0;
	int j_4 = 0;
	int max_area = 0;
	for (int first=0; first<4; first++)
	{
		for (i_1=1; i_1<length-3; i_1++)
		{
			for (j_1=i_1+2; j_1<length-1; j_1++)
			{
				//cout << i_1 << " " << j_1 << endl;
				char start_1 = molecules[first][i_1];
				char end_1   = molecules[first][j_1];
				for (int m=0; m<4; m++)
				{
					if (m == first)
					{
						continue;
					}
					//cout << m << endl;
					i_2 = molecules[m].find(start_1, 1);
					while (i_2 < length-3 && i_2!=string::npos)
					{
						for (int n=0; n<4; n++)
						{
							if (n == m || n == first)
							{
								continue;
							}
							//cout << n << endl;
							i_3 = molecules[n].find(end_1, 1);
							while (i_3 < length-3 && i_3!=string::npos)
							{
								int p = 6 - m - n - first;
								for (j_2=i_2+2, j_3=i_3+2; j_2<length-1 && j_3<length-1; j_2++, j_3++)
								{
									//cout << j_2 << " " << j_3 << endl;
									char end_2 = molecules[m][j_2];
									char end_3 = molecules[n][j_3];
									i_4 = molecules[p].find(end_2, 1);
									while (i_4 < length-3 && i_4!=string::npos)
									{
										j_4 = molecules[p].find(end_3, i_4);
										while (j_4 < length-1 && j_4!=string::npos)
										{
											if (j_4-i_4 < 2)
											{
												//	continue;
											}
											if ((j_4-i_4) == (j_1-i_1))
											{
												int area = (j_4-i_4-1) * (j_2-i_2-1);
												if (area > max_area)
												{
													max_area = area;
												}
											}
											j_4 = molecules[p].find(end_3, j_4+1);
										}
										i_4 = molecules[p].find(end_2, i_4+1);
									}
								}
								i_3 = molecules[n].find(end_1, i_3+1);
							}
						}
						i_2 = molecules[m].find(start_1, i_2+1);
					}
				}
			}
		}
	}

	return max_area;
}

int main()
{
	string molecules[4];
	cin >> molecules[0];
	while (molecules[0].compare("Q") != 0)
	{
		cin >> molecules[1];
		cin >> molecules[2];
		cin >> molecules[3];
		cout << maxArea(molecules) << endl;
		cin >> molecules[0];
	}
	return 0;
}