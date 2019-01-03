//
//  1.c
//  Algorithm
//
//  Created by taoxiaofei on 2019/1/2.
//  Copyright © 2019年 easy. All rights reserved.
//

#include "1.h"
#include <float.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 65535 // 最大字符串长度

struct student
{
    char name[50];
    int roll;
    float marks;
} s;

int main1()
{
    printf("Hello World!\n");
//
//    printf("int 存储大小 ： %lu \n", sizeof(long));
//    printf("float 最小值： %E\n", FLT_MIN);
//    printf("float 最大值： %E\n", FLT_MAX);
//    printf("精度值：%d\n", FLT_DIG);
//
//    int number;
//    printf("请输入一个整数：");
//
//    scanf("%d", &number);
//
//    printf("你输入的整数是：%d\n", number);
    
//    char s[MAX_STRING_LENGTH];
//    printf("请输入长度小于  %d 的任意字符：", MAX_STRING_LENGTH);
//    scanf("%s",s);
//
//    for(int i = 0; s[i]; i++){
//        printf("%c的ASCII:%d\t",s[i],s[i]);
//    }
    
    printf("输入信息:\n");
    
    printf("名字: ");
    scanf("%s", s.name);
    
    printf("编号: ");
    scanf("%d", &s.roll);
    
    printf("成绩: ");
    scanf("%f", &s.marks);
    
    
    printf("显示信息:\n");
    
    printf("名字: ");
    puts(s.name);
    
    printf("编号: %d\n",s.roll);
    
    printf("成绩: %.1f\n", s.marks);
    
    return 0;
}
