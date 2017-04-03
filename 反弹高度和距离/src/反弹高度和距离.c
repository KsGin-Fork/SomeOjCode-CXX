/*
 ============================================================================
 Name        : 反弹高度和距离.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float m,n,sum;
	scanf("%f%f",&m,&n);
	sum = m;
	for(int i = 1;i <= n;i++){
		sum = sum + m;
		m = m*0.5;
	}
	printf("%.2f %.2f",m,sum - 2*m);
	return EXIT_SUCCESS;
}
