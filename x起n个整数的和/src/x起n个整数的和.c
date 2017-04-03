/*
 ============================================================================
 Name        : x起n个整数的和.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,n,sum = 0;
	scanf("%d%d",&x,&n);
	for(int i = 0;i < n;i++){
		sum = sum+x+i;
	}
	printf("%d",sum);
	return EXIT_SUCCESS;
}
