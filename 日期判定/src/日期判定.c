/*
 ============================================================================
 Name        : 日期判定.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
//W = [C/4] - 2C + y + [y/4] + [13 * (M+1) / 5] + d - 1
int week_number(int c, int y, int m, int d) {
	int number;
	if(m == 1 || m == 2){
		if(y >= 1){
			y = y-1;
			m = m+12;
		}
		else{
			c = c-1;
			y = 99;
			m = m+12;
		}
	}
	number = y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
	return number;
}

int pd_year(int year) {
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	if (year % 400 == 0)
		return 1;
	return 0;
}

int pd_month(int month, int day) {
	int min_month[] = { 4, 6, 9, 11 };
	int max_month[] = {1 ,3, 5, 7, 8, 10, 12 };
	if(month > 12)  return 0;
	for (int i = 0; i < 4; i++) {
		if (month == min_month[i] && day > 30)
			return 0;
	}
	for (int i = 0; i < 7; i++) {
		if (month == max_month[i] && day > 31)
			return 0;
	}
	return 1;
}

int pd_date(int c, int y, int m, int d) {
	int year = c * 100 + y;
	if (m == 2) {
		if (pd_year(year) == 1)
			if (d > 29)
				return 0;
		if (pd_year(year) == 0)
			if (d > 28)
				return 0;
	} else {
		if (pd_month(m, d) == 0)
			return 0;
	}
	return 1;
}

void print_week( c, y, m, d) {
	if (pd_date(c, y, m, d) == 0) {
		printf("%.2d%.2d年%d月%d日是非法日期\n", c, y, m, d);
	}
	if (pd_date(c, y, m, d) == 1) {
		printf("%.2d%.2d年%d月%d日是星期", c, y, m, d);
		switch (week_number(c, y, m, d)%7) {
		case 0:
			printf("天\n");
			break;
		case 1:
			printf("一\n");
			break;
		case 2:
			printf("二\n");
			break;
		case 3:
			printf("三\n");
			break;
		case 4:
			printf("四\n");
			break;
		case 5:
			printf("五\n");
			break;
		case 6:
			printf("六\n");
			break;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	char arr[n][8];
	int c[n],y[n],m[n],d[n];
	for (int i = 0; i < n; i++) {
		scanf("%s",arr[i]);
	}
	for (int i = 0; i < n; i++) {
		c[i] = (arr[i][0] - 48) * 10 + (arr[i][1] - 48);
		y[i] = (arr[i][2] - 48) * 10 + (arr[i][3] - 48);
		m[i] = (arr[i][4] - 48) * 10 + (arr[i][5] - 48);
		d[i] = (arr[i][6] - 48) * 10 + (arr[i][7] - 48);
		print_week(c[i], y[i], m[i], d[i]);
	}
	return 0;
}
