/*
题目1：古典问题：有一对兔子，从出生后第3个月起每个月都生”一对”兔子，小兔

子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数
为多少？

程序分析：兔子的规律为数列1,1,2,3,5,8,13,21….
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    long f1,f2;
    int i;
    f1 = f2 = 1;
    for( i = 0; i <= 20; i++)
    {
        printf("%12ld %12ld",f1, f2);
        if (i % 2 == 0) {
            printf("\n");
        }
        f1 = f1 + f2;
        f2 = f1 + f2;
    }
    
    return 0;
}
