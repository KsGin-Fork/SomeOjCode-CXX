/*
 ============================================================================
 Name        : 动感的波波.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print(int n){
	for(int i = 0;i < n;i+=2){
		for(int j = n-1;j > i;j-=2)
			printf(" ");
		for(int j = 0;j <= i;j++)
			printf("*");
		printf("\n");
	}
	for(int i = n-2;i >= 0;i-=2){
			for(int j = n-1;j > i;j-=2)
				printf(" ");
			for(int j = 0;j < i;j++)
				printf("*");
			printf("\n");
	}
}

int main(void) {
	int n;
	scanf("%d",&n);
	print(n);
	return EXIT_SUCCESS;
}
