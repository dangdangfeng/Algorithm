//
//  Seven.c
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/3.
//  Copyright © 2019年 easy. All rights reserved.
//  字符串转换成整数

#include "Seven.h"
#include <ctype.h>

char* str = "   1234 ";

int StrToInt(const char* str){
    static const int MAX_INT = (int)((unsigned)~0 >> 1);
    static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
    unsigned int n = 0;

    printf("%c",*str);
    
    if (str == 0) {
        return 0;
    }
    
    while (isspace(*str)) {
        ++str;
    }
    
    int sign = 1;
    if (*str == '+' || *str == '-') {
        if (*str == '-') {
            sign = -1;
        }
        ++str;
    }
    
    while (isdigit(*str)) {
        int c = *str - '0';
        if (sign > 0 && (n > MAX_INT/10 || (n == MAX_INT/10 && c > MAX_INT % 10))) {
            n = MAX_INT;
            break;
        }else if (sign < 0 && (n >(unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10))){
            n = MIN_INT;
            break;
        }
        
        n = n * 10 + c;
        ++str;
    }
    return sign > 0 ? n : -n;
}
