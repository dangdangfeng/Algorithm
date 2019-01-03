//
//  Five.c
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/2.
//  Copyright © 2019年 easy. All rights reserved.
//

#include "Five.h"

// 暴力移位法 时间复杂度为O(m n)，空间复杂度为O(1)
void LeftShiftOne(char* s, int n)
{
    char t = s[0];  //保存第一个字符
    for (int i = 1; i < n; i++)
    {
        s[i-1] = s[i];
    }
    s[n - 1] = t;
}

void LeftRotateString(char* s, int n, int m)
{
    while (m--)
    {
        LeftShiftOne(s, n);
    }
}

// 三步反转法 时间复杂度为O(n)，空间复杂度为O(1)

void ReverseString(char* s,int from, int to)
{
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void LeftRotateStringOne(char* s,int n, int m)
{
    m %= n;//若要左移动大于n位，那么和%n 是等价的
    ReverseString(s, 0, m - 1);//反转[0..m - 1]，套用到上面举的例子中，就是X->X^T，即 abc->cba
    ReverseString(s, m, n-1);//反转[m..n - 1]，例如Y->Y^T，即 def->fed
    ReverseString(s, 0, n-1);//反转[0..n - 1]，即如整个反转，(X^TY^T)^T=YX，即 cbafed->defabc。
}
