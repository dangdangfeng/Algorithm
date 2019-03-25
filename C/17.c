/*
题目：求100之内的素数
*/

#include <stdio.h>
#include <math.h>

#define N 101

int main(int argc, char const *argv[])
{
    int i,k;
    for( i = 2; i <= 100; i++)
    {
        for( k = 2; k < i; k++)
        {
            if (i%k==0) {
                break;
            }
        }

        if (k == i)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
