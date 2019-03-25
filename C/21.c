/*
输出9*9乘法口诀
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("\n");
    int i,j;
    for( i = 1; i <= 9; i++)
    {
        for( j = 1; j <= i; j++) {
            printf("%d*%d=%-4d",i,j,i*j);
        }
        printf("\n\n");
    }
    
    return 0;
}