/*
 ============================================================================
 Name        : 互满数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int get_sum(int n){
    int sum = 0;
    for(int i = 1;i < n;i++){
        if(n % i == 0)
            sum = sum+i;
    }
    return sum;
}

int main() {
    int m ;
    scanf("%d",&m);
    for(int i = 1 ; i <= m ; i++)
    {
        int j = get_sum(i);
        if(j > i && get_sum(j) == i)
            printf("%d %d\n",i,j);
    }
    return EXIT_SUCCESS;
}
