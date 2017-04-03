/*
 ============================================================================
 Name        : 双胞胎素数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int su(int n)
{
    for(int i = 2;i < n ; i++)
       {if(n%i == 0)
         return 0;
       }
    return 1;
}


int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x < 3)
        x = 3;
    if(x % 2 == 0)
        x++;
    for(int i = x ;i<= y-2;i+=2)
    {
        if(su(i)==1 && su(i+2)==1)
          printf("(%d,%d)",i,i+2);
    }
    return 0;
}
