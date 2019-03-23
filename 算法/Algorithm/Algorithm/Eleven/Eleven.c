//
//  Eleven.c
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/4.
//  Copyright © 2019年 easy. All rights reserved.
//  寻找数组中的最大值和最小值

#include "Eleven.h"
#include <stdbool.h>

// 把数组中相邻的两个元素分为一组，然后比较这两个元素，较大者和max比较，如果大于max则更新max，较小者和min比较，小于min则更新min。算法的时间复杂度为O(1.5*n)
int main1()
{
    printf("Hello World!\n");
    return 0;
}
void find_max_min(int *a, int length, int *max, int *min){
    if (length <= 0) {
        return;
    }
    if (length <= 1) {
        *max = *min = a[length -1];
        return;
    }
    
    *max = a[0] > a[1] ? a[0] : a[1];
    *min = a[0] > a[1] ? a[1] : a[0];
    int i;
    int n;
    
    if (length % 2) {
        n = length - 1;
    }else{
        n = length;
    }
    
    for (i = 2; i < n; i+=2) {
        if (a[i] > a[i+1]) {
            *max = *max > a[i] ? *max : a[i];
            *min = *min > a[i + 1] ? a[i+1]:*min;
        }else{
            *max = *max > a[i+1] ? *max : a[i+1];
            *min = *min > a[i] ? a[i]:*min;
        }
    }
    
    if (i < length) {
        *max = *max > a[i] ? *max : a[i];
        *min = *min > a[i] ? a[i] : *min;
    }
}
