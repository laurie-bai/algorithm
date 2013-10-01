#include "array.h"
#define N 10

void merge(int *, int, int, int);
void merge_sort(int *, int, int);

int main(void)
{
	int a[N];

	init_array(a, N);
	print_array(a, N);
	merge_sort(a, 0, N-1);
	print_array(a, N);

	return 0;
}

void merge(int *a, int start, int mid, int final)
{
	int i, j, k;
	int tmp[N] = {0};

	k = start;
	i = start;
	j = mid+1;
	while (i <= mid && j <= final) {
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while (i <= mid)
		tmp[k++] = a[i++];
	while (j <= final)
		tmp[k++] = a[j++];
	for (i = start; i <= final; i++)
		a[i] = tmp[i]; 
}

void merge_sort(int *a, int start, int final)
{
	int mid = (start+final)/2;
	
	if (start >= final)
		return;
	merge_sort(a, start, mid);
	merge_sort(a, mid+1, final);
	merge(a, start, mid, final);
}
