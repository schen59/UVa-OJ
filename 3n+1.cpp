#include "ThreeNPlusOne.h"
#include <stdio.h>


//int main() {
//	ThreeNPlusOne *threeNPlusOne = new ThreeNPlusOne();
//    unsigned int i, j;
//	while (scanf("%d %d", &i, &j) == 2) {
//		printf("%d %d %d\n", i, j, threeNPlusOne->maxCircleLength(i, j));
//	}
//	return 0;
//}

#include <stdio.h>


int cl[1000001];

int circleLength(unsigned int number)
{
	if (number >= 1000001)
	{
		if (number%2 == 0)
		{
			return circleLength(number/2) + 1;
		}
		else
		{
			return circleLength(number*3 + 1) + 1;
		}
	}
	else
	{
		
		int previous, post;
		if (number == 1)
		{
			cl[1] = 1;
			return cl[1];
		}
		if (cl[number] != 0)
		{
			return cl[number];
		}
		else if (number%2 == 0)
		{
			cl[number] = circleLength(number/2) + 1;
			return cl[number];
		}
		else
		{
			cl[number] = circleLength(number*3 +1) + 1;
			return cl[number];
		}
	}
}

int maxCircleLength(int i, int j)
{
	int maxLength = 0;
	int k;
	int length;
	for (k=i; k<=j; k++)
	{
		length = circleLength(k);
		if (length > maxLength)
		{
			maxLength = length;
		}
	}
	return maxLength;
}

int main()
{
	int i, j;
	int flag = 0;
	int k, m, temp;
	for(k=0; k<1000001; k++) 
	{
		cl[k] = 0;
	}
	while (scanf("%d %d", &i, &j) == 2) {
		flag = 0;
		if(i > j) 
		{
			temp = i;
			i = j;
			j = temp;
			flag = 1;
		}
		if (flag == 1)
		{
			printf("%d %d %d\n", j, i, maxCircleLength(i, j));
		}
		else{
			printf("%d %d %d\n", i, j, maxCircleLength(i, j));
		}
		:
	}
	return 0;
}