/*
题目3：打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位
数字立方和等于该数本身。例如：153是一个“水仙花数”，因为153=1的三次方
＋5的三次方＋3的三次方。

程序分析：利用for循环控制100-999个数，每个数分解出个位，十位，百位。
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i,j,k,n;
    printf("water flower 'number' is :");
    for( n = 100; n < 1000; n++)
    {
        i = n/100;
        j = n / 10 % 10;
        k = n%10;
        if (n == i*i*i + j*j*j + k*k*k)  {
            printf("%-5d",n);
        }
        
    }
    printf("\n");
    
    return 0;
}
