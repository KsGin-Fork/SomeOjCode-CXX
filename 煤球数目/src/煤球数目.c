/*
 ============================================================================
 Name        : 煤球数目.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int get_sum(int n){
	if(n == 1) return 1;
	return n+get_sum(n-1);
}
int get_number(int n){
	int sum;
	for(int i = 1;i <= n;i++){
		sum = sum + get_sum(i);
	}
	return sum;
}
int main(void) {
	int n;
	scanf("%d",&n);
	printf("%d",get_number(n));
	return EXIT_SUCCESS;
}
