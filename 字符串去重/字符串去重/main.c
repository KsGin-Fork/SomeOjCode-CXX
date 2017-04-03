//
//  main.c
//  字符串去重
//
//  Created by 杨帆 on 16/5/18.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char arr[100];
    scanf("%s",arr);
    int arr1[strlen(arr)];
    for (int i = 0; i < strlen(arr); i++)
        arr1[i] = 0;
    for(int i = 0;i < strlen(arr);i++)
        for(int j = 0;j < i ;j++)
            if(arr[j] == arr[i])
                arr1[i] = 1;
    for(int i = 0;i < strlen(arr);i++)
        if(arr1[i] == 0)
            printf("%c",arr[i]);
    printf("\n");
    return 0;
}
