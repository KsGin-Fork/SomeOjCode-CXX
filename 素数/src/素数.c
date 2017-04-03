/*
 ============================================================================
 Name        : 素数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int su(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i = a;i < b;i++){
		if(su(i) == 1)
			printf("%d ",i);
	}
	return EXIT_SUCCESS;
}
