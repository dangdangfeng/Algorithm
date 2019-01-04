//
//  Eight.c
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/3.
//  Copyright © 2019年 easy. All rights reserved.
//  回文判断

#include "Eight.h"

// 从头向两边
bool IsPalindrome(const char *s, int n)
{
    if (s == NULL || n < 1) {
        return false;
    }
    const char* front, *back;
    
    front = s;
    back = s+n - 1;
    
    while (front < back) {
        if (*front != *back) {
            return false;
        }
        ++front;
        --back;
    }
    
    return true;
}

// 从中间到两边
bool IsPalindrome2(const char* s, int n){
    if (s ==NULL || n < 1) {
        return false;
    }
    const char* first, *second;
    
    int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;
    first = s + m;
    second = s + n - 1 - m;
    
    while (first >= s) {
        if (*first != *second) {
            return false;
        }
        --first;
        ++second;
    }
    return true;
}
