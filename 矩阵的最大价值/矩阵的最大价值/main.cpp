//
//  main.cpp
//  矩阵的最大价值
//
//  Created by 杨帆 on 16/5/19.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int f[502][502] ,v[502][502];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>v[i][j];
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            f[x][y] = (f[x-1][y]>f[x][y-1]?f[x-1][y]:f[x][y-1]) + v[x][y];
    cout<<f[n][n];
    return 0;
}