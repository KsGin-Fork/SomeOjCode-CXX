/*
 ============================================================================
 Name        : 星系炸弹.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main() {
	int year, month, day, num, flag = 1;
	scanf("%d-%d-%d %d", &year, &month, &day, &num);
	num += day;
	while (num > 0 && flag == 1) {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (num > 31) {
				num -= 31;
				month++;
			} else {
				day = num;
				flag = 0;
			}
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				if (num > 29) {
					num -= 29;
					month++;
				} else {
					day = num;
					flag = 0;
				}
			} else {
				if (num > 28) {
					num -= 28;
					month++;
				} else {
					day = num;
					flag = 0;
				}
			}break;
		default:
			if (num > 30) {
				num -= 30;
				month++;
			} else {
				day = num;
				flag = 0;
			}
			break;
		}
		if (month == 13) {
			month = 1;
			year++;
		}
	}
	printf("%d-%02d-%02d", year, month, day);
	return 0;

}
