//
//  main.cpp
//  找出最大的乘积
//
//  Created by 杨帆 on 16/5/18.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int N[n],M[n],a[n][100],sum[n],num1[n],num2[n];
    for(int i = 0;i < n;i++){
        sum[i] = 1;
        cin>>N[i]>>M[i];
        for(int j = 0;j < N[i];j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0;i < n ; i++){
        for(int j = 0;j < N[i];j++){
            for (int k = j; k < N[i]; k++) {
                if(a[i][j] >= a[i][k]){
                    int temp;
                    temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    
    for(int k = 0 ; k < n; k++){
        for(int i = N[k] - 1,j = 0; i >= j && M[k] != 0;){
            num1[k] = a[k][i] * a[k][i-1];
            num2[k] = a[k][j] * a[k][j+1];
            if(num1[k] <= num2[k] && M[k] >= 2){
                sum[k] *= num2[k];
                j += 2;
                M[k] -= 2;
            }
            else{
                sum[k] *= a[k][i];
                i--;
                M[k]--;
            }
        }
        cout<<sum[k]<<"\n";
    }
    return 0;
}
