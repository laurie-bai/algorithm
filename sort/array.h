#include <stdio.h>
#include <stdlib.h>

void init_array(int *a, int len)
{
	int i;
	
	srand(time(NULL));
	for (i = 0; i < len; i++)
		a[i] = rand()%100;
}

void print_array(int *a, int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
