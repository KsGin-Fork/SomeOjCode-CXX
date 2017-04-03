/*
 ============================================================================
 Name        : 阶乘和.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getjc(int num){
	if(num == 1) return 1;
	return getjc(num-1) * num;
}

int main(void) {
	int n,sum = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		sum = sum+getjc(i);
	}
	printf("%d",sum);
	return EXIT_SUCCESS;
}
