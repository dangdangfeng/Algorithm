/*
题目6：输入两个正整数m和n，求其最大公约数和最小公倍数。

程序分析：利用辗除法。
*/

#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,num1,num2,temp;
    printf("please input two numbers:\n");

    scanf("%d %d",&num1,&num2);

    a = num1;b = num2;

    while(b!=0){
        temp = a % b;
        a = b;
        b = temp;
    }
    printf("公约数:%d\n",a);
    printf("公倍数:%d\n",num1*num2/a);

    return 0;
}
