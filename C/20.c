/*
题目：取一个整数a从右端开始的4～7位。

程序分析：可以这样考虑：
(1)先使a右移4位。
(2)设置一个低4位全为1,其余全为0的数。可用~(~0<<4)
(3)将上面二者进行&运算。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned a,b,c,d;
    scanf("%o",&a);
    b = a>>4;
    c = ~(~0<<4);
    d=b&c;
    printf("%o\n%o\n",a,d);
    return 0;
}
