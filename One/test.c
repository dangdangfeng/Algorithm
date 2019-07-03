#include <stdio.h>
#include <stdlib.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

// ++p 和 p++
int main(int argc, char const *argv[])
{
    int array[6] = {1,2,3,4,5,6};
    int *p = &array[0];
    int max = Max(*(++p),1);
    printf("%d %d\n",max,*p);
    return 0;
}