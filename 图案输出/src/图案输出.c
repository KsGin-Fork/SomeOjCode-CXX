/*
 ============================================================================
 Name        : 图案输出.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print(int n){
	if(n == 1)
		printf("*");
	else{
		printf("*");
		for(int i = 0;i < n-2;i++)
			printf("+");
		printf("*");
	}
}

int main(void) {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i = i+2){
		print(i);
		printf("\n");
	}
	for(int i = n-2;i >= 1;i = i-2){
		print(i);
		printf("\n");
	}
	return EXIT_SUCCESS;
}
