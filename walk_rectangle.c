#include <stdio.h>
/*
* 给出一个m*n的矩形，编程求从左上角走到右下角的路径数
* 限制只能向右或向下移动，不能回退
*/
//数学解法，从左上到右下一共2n步，向右n步。所以结果是：C2n~n
//递归解法
int roadn(int m, int n)
{
	if (m == 1)
		return n+1;
	if (n == 1)
		return m+1;
	return roadn(m-1, n) + roadn(m, n-1);
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("usage: %s m n\n", argv[0]);
		return -1;
	}
	
	int m, n;

	m = atoi(argv[1]);
	n = atoi(argv[2]);
	printf("Total choic nums: %d\n", roadn(m, n));

	return 0;
}
