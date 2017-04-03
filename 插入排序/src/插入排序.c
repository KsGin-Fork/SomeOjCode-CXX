/*
 ============================================================================
 Name        : 插入排序.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#define N 100
int main(){
    int arr[N];
    int j = 0;
    while((scanf("%d",&arr[j])) != EOF){
        for(int m = 0;m <= j;m++){
            for(int n = m;n <= j;n++)
                if(arr[m] > arr[n]){
                    int t;
                    t = arr[m];
                    arr[m] = arr[n];
                    arr[n] = t;
                }
            }
        for(int i = 0;i <= j;i++){
            printf("%d ",arr[i]);
        }
        j++;
        printf("\n");
    }
    return 0;
}
