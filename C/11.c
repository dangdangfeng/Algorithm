/*
一只猴子摘了N个桃子第一天吃了一半又多吃了一个,第二天又吃了余下的
一半又多吃了一个,到第十天的时候发现还有一个.
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i,s,n=1;
    for( i = 1 ; i < 10; i++)
    {
        s = (n+1)*2;
        n = s;
    }
    printf("第一天共摘了%d个桃\n",s);
    return 0;
}
