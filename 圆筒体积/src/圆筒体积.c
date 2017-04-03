/*
 ============================================================================
 Name        : 圆筒体积.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

float get_sqart(float n,float m,float h){
	return (PI*n*n-PI*m*m)*h;
}

int main(void) {
	float m , n ,h;
	scanf("%f,%f,%f",&m,&n,&h);
	printf("%.2lf",get_sqart(m,n,h));
	return EXIT_SUCCESS;
}
