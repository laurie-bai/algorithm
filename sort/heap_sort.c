#include "array.h"

#define left(x) (x<<1)
#define right(x) ((x<<1)+1)
#define swap(t, x, y) {t tmp = x;x = y; y = tmp;}
#define N 10

void max_heapfify(int *, int, int);
void build_max_heap(int *, int);
void heap_sort(int *, int);

int main(int argc, char *argv[])
{
	int a[N];
	init_array(a, N);
	print_array(a, N);
	heap_sort(a, N);
	print_array(a, N);

	return 0;
}

void max_heapfify(int *a, int i, int len)
{
	int l, r, max;

	l = left(i);
	r = right(i);
	if (l < len && a[i] < a[l])
		max = l;
	else
		max = i;
	if (r < len && a[r] > a[max])
		max = r;
	if (max != i) {
		swap(int, a[i], a[max]);
		max_heapfify(a, max, len);
	}
}

void build_max_heap(int *a, int len)
{
	int i;

	for (i = len/2; i >= 0; i--)
		max_heapfify(a, i, len);
}

void heap_sort(int *a, int len)
{
	int i;

	build_max_heap(a, len);
	for (i = len-1; i > 0; i--) {
		swap(int, a[0], a[i]);
		max_heapfify(a, 0, i);
	}
}
