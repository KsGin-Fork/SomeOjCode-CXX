/*
 ============================================================================
 Name        : 生日蜡烛.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>

void get_number(int n){
	for(int i = 1;i < n;i++){
		if((2*n) % (2*i+1) == 0 && i > n/(2*i+1)){
			printf("%d %d",i-n/(2*i+1)+1,i+n/(2*i+1));
			break;
		}
		if(n % i == 0 && i >= n/i/2){
			printf("%d %d",i-n/i/2,i+n/i/2);
			break;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	get_number(n);
	return 0;
}
