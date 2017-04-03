/*
 ============================================================================
 Name        : 卖西瓜.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int sum = 1020,day = 0;
	while(sum > 0){
		day++;
		sum = sum/2 - 2;
	}
	printf("%d",day);
	return EXIT_SUCCESS;
}
