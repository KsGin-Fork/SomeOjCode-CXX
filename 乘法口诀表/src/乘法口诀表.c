/*
 ============================================================================
 Name        : 乘法口诀表.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void _print(){
	for(int i = 1; i <= 9;i++){
		for(int j = 1;j <= i;j++){
			if(j < i)  printf("%d*%d=%2d  ",j,i,j*i);
			else printf("%d*%d=%2d",j,i,j*i );
		}
		printf("\n");
	}
}

int main(void) {
	_print();
	return EXIT_SUCCESS;
}
