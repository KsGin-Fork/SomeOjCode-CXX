/*
 ============================================================================
 Name        : 数字各位.c
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
	fgets(arr,100,stdin);
	printf("%d\n",(int)strlen(arr)-1);
	for(int i = 0 ;i < strlen(arr)-1;i++){
		printf("%d",arr[i] - 48);
		if(i < strlen(arr)-1)
			printf(" ");
	}
	printf("\n");
	for(int i = strlen(arr) - 2;i >= 0;i-- )
		printf("%d",arr[i]-48);
	return EXIT_SUCCESS;
}
