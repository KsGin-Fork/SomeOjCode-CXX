/*
 ============================================================================
 Name        : 各位奇数平方和.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char arr[100];
	int sum = 0;
	gets(arr);
	for(int j = 0;j < strlen(arr)+1;j++)
		if(arr[j] % 2 != 0)
			sum = sum + (arr[j]-48)*(arr[j]-48);
	printf("%d",sum);
	return EXIT_SUCCESS;
}
