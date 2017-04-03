/*
 ============================================================================
 Name        : 阶乘.c
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
	int i;
	scanf("%d",&i);
	printf("%d",getjc(i));
	return EXIT_SUCCESS;
}
