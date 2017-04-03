//
//  main.cpp
//  字符串最大价值
//
//  Created by 杨帆 on 16/5/19.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    char arr[10000];
    int word[26];
    long int sum = 0;
    for(int i = 0;i < 26;i++){
        word[i] = 0;
    }
    cin>>arr;
    for(int i = 0 ; i < strlen(arr) ; i++)
        word[(int)toupper(arr[i])-65]++;
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 25 - i;j++){
            if(word[j] < word[j+1]){
                int temp;
                temp = word[j];
                word[j] = word[j+1];
                word[j+1] = temp;
            }
        }
    }
    for(int i = 0;i < 26; i++){
        sum = sum + word[i]*(26-i);
    }
    cout<<sum;
    return 0;
}
