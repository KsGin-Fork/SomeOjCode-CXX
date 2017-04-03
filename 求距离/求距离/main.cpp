//
//  main.cpp
//  求距离
//
//  Created by 杨帆 on 16/5/18.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin>>n;
    float distant[100];
    for(int i = 0;i < n;i++){
        float x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        distant[i] = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    }
    for(int i = 0;i < n;i++){
        cout<<fixed<<setprecision(2)<<distant[i]<<endl;
    }
    return 0;
}
