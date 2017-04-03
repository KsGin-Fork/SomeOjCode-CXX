/*
 ============================================================================
 Name        : 水仙花数1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void num_print(){
	for(int i = 100;i < 1000;i++){
		if(pow((i/100),3)+pow((i%100)/10,3)+pow(i%10,3) == i)
			printf("%d ",i);
	}
}

int main(void) {
	num_print();
	return EXIT_SUCCESS;
}
