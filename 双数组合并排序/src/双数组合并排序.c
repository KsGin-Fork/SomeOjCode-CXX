/*
 ============================================================================
 Name        : 双数组合并排序.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include<stdio.h>
int main(){
    int m,n;
    scanf("%d,%d",&m,&n);
    int arr1[m+n],arr2[n];
    for(int i = 0;i < m;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&arr2[i]);
        arr1[m+i] = arr2[i];
    }
    for(int i = 0;i < m+n;i++)
        for(int j = i;j < m+n;j++)
            if(arr1[i] > arr1[j]){
                int t;
                t = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = t;
            }
    for(int k = 0;k < m+n;k++)
        printf("%d ",arr1[k]);
    return 0;
}
