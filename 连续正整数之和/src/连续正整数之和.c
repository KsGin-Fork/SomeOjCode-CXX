/*
 ============================================================================
 Name        : 连续正整数之和.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdio.h>
void print_number(int a,int b){
	for(int i = a;i <= b;i++){
		if(i<b)
			printf("%d+",i);
		else printf("%d",i);
	}
	printf("\n");
}

int pd_equal(int n,int a,int b){
	int sum = 0;
	for(int i = a;i <= b;i++){
		sum = sum+i;
	}
	if(sum == n)  return 1;
	else return 0;
}
void get_number(int n){
	int flag = 0;
	for(int i = 1;i < n;i++){
		if((2*n) % (2*i+1) == 0 && i > n/(2*i+1) && pd_equal(n,i-n/(2*i+1)+1,i+n/(2*i+1)) == 1){
			printf("%d=",n);
			print_number(i-n/(2*i+1)+1,i+n/(2*i+1));
			flag++;
		}
		if(n % i == 0 && i > n/i/2 && pd_equal(n,i-n/i/2,i+n/i/2) == 1){
			printf("%d=",n);
			print_number(i-n/i/2,i+n/i/2);
			flag++;
		}
	}
	if(flag == 0)  printf("NONE");
}

int main(){
	int n;
	scanf("%d",&n);
	get_number(n);
	return 0;
}

