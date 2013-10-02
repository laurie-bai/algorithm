#include <ctype.h>
#include <stdio.h>

#define T 1000
#define LINE_MAX 1024

int min_minute(int, int, int);
void assign(int *, int *, int *, char *);

int main(int argc, char *argv[])
{
	int i, t, n, k, m;
	char line[T][LINE_MAX];

	scanf("%d\n", &t);
	for (i = 0; i < t; i++) {
		fgets(line[i], LINE_MAX, stdin);
	}
	for (i = 0; i < t; i++) {
		assign(&n, &k, &m, line[i]);
		printf("%d\n", min_minute(n, k, m));
	}
	
	return 0;
}

int min_minute(int n, int k, int m)
{
	if (m <= n)
		return (n*k)%m == 0 ? n*k/m : n*k/m+1;
	return k;
}

void assign(int *np, int *kp, int *mp, char *s)
{
	int i, j, num[10];

	for (i = 0; i < 10; i++)
		num[i] = 0;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (!isspace(s[i]))
			num[j] = 10*num[j]+(s[i]-'0');
		else
			j++;
	}
	*np = num[0];
	*kp = num[1];
	*mp = num[2];
}
