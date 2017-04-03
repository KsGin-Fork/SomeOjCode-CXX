/*
 ============================================================================
 Name        : 求和.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
float get_sum(int number){
	float sum = 0,temp = 1,num;
	for(int i = 1;i <= number;i++){
		num = temp / i;
		sum = sum + num;
		temp = temp*-1;
	}
	return sum;
}
int main(void) {
	int number;
	scanf("%d",&number);
	printf("%.2f",get_sum(number));
	return EXIT_SUCCESS;
}
