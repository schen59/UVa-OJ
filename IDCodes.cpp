#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() 
{
	char id_code[100];
	int length = 0;
	scanf("%s", id_code);
	while (id_code[0] != '#')
	{
		length = strlen(id_code);
		if (next_permutation(id_code, id_code+length))
		{
			printf("%s\n", id_code);
		}
		else
		{
			printf("No Successor\n");
		}
		scanf("%s", id_code);
	}
	return 0;
}