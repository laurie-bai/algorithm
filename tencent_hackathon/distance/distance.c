#include <stdio.h>
#include <stdlib.h>

#define YEAR  2013
#define MONTH 3
#define DAY   24
#define LINE_MAX 2000

int  day_nums_of_month(int, int);
int  day_nums_of_last_month(int, int);
void back_date(int, int *, int *, int *);
void future_date(int, int *, int *, int *);

int main(int argc, char *argv[])
{
	int n, i;
	int day, month, year;
	int line[LINE_MAX] = {0};
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &line[i]);
	}
	for (i = 0; i < n; i++) {
		future_date(line[i], &year, &month, &day);
		printf("%04d/%02d/%02d ", year, month, day);
		back_date(line[i], &year, &month, &day);
		printf("%04d/%02d/%02d\n", year, month, day);
	}
	
	return 0;
}

int day_nums_of_month(int year, int month)
{
	int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int leap_year, nums;

	leap_year = (year%4 == 0 && year%100 != 0) || (year%400 ==0);
	if (month != 2)
		nums = m[month];
	else if (leap_year)
		nums = 29;
	else
		nums = 28;

	return nums;
}

int day_nums_of_last_month(int year, int month)
{
	int nums;

	if (month == 1)
		nums = day_nums_of_month(year-1, 12);
	else
		nums = day_nums_of_month(year, month-1);

	return nums;
}

void back_date(int days, int *year, int *month, int *day)
{
	int m = MONTH, y = YEAR, nums;
	
	while (days > (nums = day_nums_of_last_month(y, m))) {
		m--;
		days -= nums;
		if (m == 0) {
			m = 12;
			y--;
		}
	}
	*year = y;
	*month = m;
	if (days < DAY)
		*day = DAY-days;
	else {
		*day = nums-(days-DAY);
		(*month)--;
	}
}

void future_date(int days, int *year, int *month, int *day)
{
	int m = MONTH, y = YEAR, d, nums;

	while (days > (nums = day_nums_of_month(y, m))) {
		m++;
		days -= nums;
		if (m == 13) {
			m = 1;
			year++;
		}
	}
	*year = y;
	*month = m;
	if (DAY+days <= nums)
		*day = DAY+days;
	else {
		*day = DAY+days-nums;
		(*month)++;
	}
}
