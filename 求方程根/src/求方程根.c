/*
 ============================================================================
 Name        : 求方程根.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void number(float a,float b,float c){
	if((b*b-4*a*c) > 0 ){
		printf("x1=%.3f ",((-b+sqrt(b*b-4*a*c)) / (2*a)));
		printf("x2=%.3f",((-b-sqrt(b*b-4*a*c)) / (2*a)));
	}
	else if(b*b-4*a*c == 0){
		printf("x1=%.3f x2=%.3f",(-b/(2*a)),(-b/(2*a)));
	}
	else{
		printf("x1=%.3f+%.3fi ",(-b/(2*a))  ,   sqrt(fabs(b*b-4*a*c))/(2*a));
		printf("x2=%.3f-%.3fi",(-b/(2*a))  ,   sqrt(fabs(b*b-4*a*c))/(2*a));
	}

}

int main(void) {
	float a,b,c;
	scanf("%f%f%f",&a,&b,&c);
	number(a,b,c);
	return EXIT_SUCCESS;
}
