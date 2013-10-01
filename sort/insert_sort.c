#include "array.h"

#define N 10

void insert_sort(int *, int, int);

int main(int argc, char *argv[])
{
	int i, a[N];
	
	init_array(a, N);
	print_array(a, N);
	insert_sort(a, 0, N-1);
	print_array(a, N);

	return 0;
}

void insert_sort(int *a, int start, int final)
{
	int i, j, tmp;

	for (i = start+1; i <= final; i++) {
		j = i-1;
		tmp = a[i];
		while (tmp < a[j] && j >= start) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}
}
