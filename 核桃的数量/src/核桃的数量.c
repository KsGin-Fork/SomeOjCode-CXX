/*
 ============================================================================
 Name        : 核桃的数量.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int MaxDenominator(int a, int b) {
	if (a % b == 0)
		return b;
	return MaxDenominator(b, a % b);
}
int MinMultiple(int a, int b) {
	return a * b / MaxDenominator(a, b);
}

int main(void) {
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",MinMultiple(MinMultiple(a,b),c));
	return EXIT_SUCCESS;
}
