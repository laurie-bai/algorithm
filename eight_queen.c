#include <stdio.h>
#include <stdlib.h>

#define N 8
#define TRUE 1
#define FALSE 0

int count = 1;
int output(int *pos);
void place(int *pos, int row);
int can_place(int *pos, int row, int col);

int main(int argc, char *argv[])
{
	int i;
	int row = 0;
	int col = 0;
	int pos[N];    //col of every row

	for (i = 0; i < N; i++)
		pos[i] = 0;
	place(pos, 0);

	return 0;
}

int can_place(int *pos, int row, int col)
{
	int i;

	if (row == 0)
		return TRUE;
	for (i = 0; i < row; i++) {
		if (pos[i] == col || abs(pos[i]-col) == row-i)
			return FALSE;
	}
	return TRUE;
}

//place a queen in a col of the row
void place(int *pos, int row)
{
	int j;

	for (j = 0; j < N; j++) {
		if (can_place(pos, row, j)) {
			pos[row] = j;
			if (row == N-1)
				output(pos);
			else
				place(pos, row+1);
		}
	}
}

int output(int *pos)
{
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (pos[i] == j)
				printf("$ ");
			else
				printf("- ");
		}
		printf("\n");
	}
	printf("\n\n");
}
