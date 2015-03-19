#include <stdio.h>
#include <string>

int main()
{
	int list[50];
	int i = 0;
	int input;

	while((input = getchar()) != 10) //
	{
		list[i++] = input - '0';
	}

	int a;
	for (a=0;a<i;a++)
	   printf("%d ",list[a]);

	system("pause");


	return EXIT_SUCCESS;
}
