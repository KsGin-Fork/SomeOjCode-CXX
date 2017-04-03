/*
 ============================================================================
 Name        : 最大公约数和最小公倍数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include<stdio.h>
#include<stdlib.h>
int main() {
	int m, n;
	int f(int m, int n);
	scanf("%d%d", &m, &n);
	printf("%d %d", f(m, n),m * n / f(m, n));
	return EXIT_SUCCESS;
}
int f(int m, int n) {
	int c;
	c = m % n;
	while (c != 0) {
		m = n;
		n = c;
		c = m % n;
	}
	return n;
}

