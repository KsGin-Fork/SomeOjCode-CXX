/*
 ============================================================================
 Name        : 水仙花数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int wfn(int n){
	int g,s,b;
	g = n % 10;
	s = ((n-g) % 100)/10;
	b = n/100;
	if(pow(g,3) + pow(s,3) + pow(b,3) == n) return 1;
	return 0;
}

int main(void) {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i < n;i++)
		scanf("%d",&arr[i]);
	for(int i = 0;i < n;i++){
		if(wfn(arr[i]) == 1)  printf("%d是水仙花数\n",arr[i]);
		else printf("%d不是水仙花数\n",arr[i]);
	}
	return EXIT_SUCCESS;
}
