/*
 ============================================================================
 Name        : n个a之和.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getsum(int a,int n){
	int number = 0;
	for(int i = 0;i <= n;i++){
		number = number + a*pow(10,i);
	}
	return number;
}

int main(void) {
	int a,n,sum = 0;
	scanf("%d%d",&a,&n);
	for(int i = 0;i < n;i++){
		sum = sum + getsum(a,i);
	}
	printf("%d",sum);
	return EXIT_SUCCESS;
}
