/*
在for循环中的区别

思考：for循环中i++与++i有区别吗？

实例：通过自加算出从0~100的结果，本着简单原则。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0, n = 0, m = 0;
    for(i = 0; i <= 100;i++){
        m = m + 1;
    }
    for(i = 0; i <= 100; ++i){
        n = n + 1;
    }
    printf("%d\n",m);
    printf("%d\n",n);
    return 0;
}
