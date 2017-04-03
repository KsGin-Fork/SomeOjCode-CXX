/*
 ============================================================================
 Name        : 矩阵列前移一位.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
int main(){
    int m,n,temp;

    while((scanf("%d,%d",&m,&n)) != EOF){

        int arr[m][n];
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                scanf("%d",&arr[i][j]);
        for(int i = 0;i < m;i++){
            temp = arr[i][0];
            for(int j = 0;j < n-1;j++)
                arr[i][j] = arr[i][j+1];
            arr[i][n-1] = temp;
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                printf("%5d",arr[i][j]);
            printf("\n");
        }
    }
        return 0;
}
