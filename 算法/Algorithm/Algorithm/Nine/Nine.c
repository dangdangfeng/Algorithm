//
//  Nine.c
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/3.
//  Copyright © 2019年 easy. All rights reserved.
//  给定一个字符串，求它的最长回文子串的长度

#include "Nine.h"
#include <string.h>

// 如果一段字符串是回文，那么以某个字符为中心的前缀和后缀都是相同的
int LongestPalindrome(const char *s, int n){
    int i, j, max, c = 0;
    if (s == 0 || n < 1) {
        return 0;
    }
    max = 0;
    
    for (i = 0; i < n; ++i) {// i is the middle point of the palindrome
        for (j = 0; (i - j >= 0) && (i + j < n); ++j) {// if the length of the palindrome is odd
            if (s[i - j] != s[i+j]) {
                break;
            }
            c = j * 2 + 1;
        }
        if (c > max) {
            max = c;
        }
        for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j) {// for the even case
            if (s[i - j] != s[i + j + 1]) {
                break;
            }
            c = j * 2 + 2;
        }
        if (c > max) {
            max = c;
        }
    }
    return max;
}

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
// O(N)解法 Manacher算法
int LongestPalindrome1(const char *s){
    //输入，并处理得到字符串s
    int p[1000], mx = 0, id = 0;
    memset(p, 0, sizeof(p));
    int i;
    for (i = 1; s[i] != '\0'; i++)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (s[i + p[i]] == s[i - p[i]])
            p[i]++;
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            id = i;
        }
    }
    //找出p[i]中最大的
    int max = 0;
    for (int j = 0; j < i; j ++ ) {
        if (p[j] > max) {
            max = p[j];
        }
    }
    return max;
}
