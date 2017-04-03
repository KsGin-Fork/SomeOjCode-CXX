/*
 ============================================================================
 Name        : 完数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pd_number(int n){
	int sum = 0;
	for(int i = 1;i < n;i++){
		if(n % i == 0){
			sum = sum + i;
		}
	}
	if(n == sum)  return 1;
	else return 0;
}

int main(void) {
	int number;
	scanf("%d",&number);
    for(int i = 1;i <= number;i++){
    	if(pd_number(i) == 1) printf("%d ",i);
    }
	return EXIT_SUCCESS;
}
