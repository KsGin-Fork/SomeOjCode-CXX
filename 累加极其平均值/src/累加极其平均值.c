/*
 ============================================================================
 Name        : 累加极其平均值.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
int main()
{
    int sum = 0,num=0,a;
    scanf("%d",&a);
    while (a!= -1)//-1结束输入
    {
        sum+=a;
        num++;
        scanf("%d",&a);
    }
    printf("%d %.2f",sum,1.0*sum/num);
    return 0;
}
