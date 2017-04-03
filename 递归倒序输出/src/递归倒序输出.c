/*
 ============================================================================
 Name        : 递归倒序输出.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_sort(char *arr,int n){
	printf("%d",arr[n]-48);
	if(n == 0)  exit(1);
	else return print_sort(arr,n-1);
}

int main(void) {
	char arr[100];
	gets(arr);
	print_sort(arr,strlen(arr)-1);
	return EXIT_SUCCESS;
}
