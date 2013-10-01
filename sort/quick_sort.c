#include "array.h"

#define N 10

int partition(int *, int, int);
void quick_sort(int *, int, int);

int main(void)
{
	int a[N];

	init_array(a, N);
	print_array(a, N);
	quick_sort(a, 0, N-1);
	print_array(a, N);

	return 0;
}

int partition(int *a, int start, int final)
{
	int i, j, temp;

	for (i = start-1, j = start; j <= final; j++) {
		if (a[j] <= a[final]) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	
	return i;
}

void quick_sort(int *a, int start, int final)
{
	int mid;
	
	if (start >= final)
		return;
	mid = partition(a, start, final);
	quick_sort(a, start, mid-1);
	quick_sort(a, mid+1, final);
}
