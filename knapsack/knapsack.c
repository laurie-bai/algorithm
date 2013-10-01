/*--------01背包---------*/
#include <stdio.h>

#define N 10
#define MAX 100

void knapsack(int *, int *, int [][MAX+1], int, int);
void print_choose(int *, int *, int [][MAX+1], int, int);

int main(int argc, char *argv[])
{
	int w[N+1] = {0,10,20,32,23,45,21,1,2,31,50};     //每件商品的重量
	int v[N+1] = {0,30,69,47,34,45,32,12,23,95,57};   //每件商品的价值
	int c[N+1][MAX+1];

	knapsack(w, v, c, MAX, N);
	print_choose(w, v, c, MAX, N);

	return 0;
}

void knapsack(int *w, int *v, int c[][MAX+1], int max, int n)
{
	int i, remain;

	for (i = 0; i <= max; i++)
		c[0][i] = 0;
	for (i = 1; i <= n; i++) {
		c[i][0] = 0;
		for (remain = 1; remain <= max; remain++) {
			int not_choose_i = c[i-1][remain-w[i]]+v[i];
			if (not_choose_i > c[i-1][remain] && w[i] <= remain)
				c[i][remain] = not_choose_i;
			else
				c[i][remain] = c[i-1][remain];
		}
	}
}

//打印选择方案
void print_choose(int *w, int *v, int c[][MAX+1], int max, int n)
{
	int i, remain = max;

	for (i = n; i > 0; i--) {
		if (remain >= w[i] && c[i][remain]-c[i-1][remain-w[i]] == v[i]) {
			printf("select %3d, weight : %3d, value : %3d\n", i, w[i], v[i]);
			remain -= w[i];
		}
	}
}
