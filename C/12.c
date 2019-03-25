/*
迭代法求一个数的平方根 
*/

#define Epsilon 1.0E-6 /*控制解的精度*/
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float a, x0, x1;
    printf("请输入要求的数：");
    scanf("%f",&a);
    x0 = a / 2;
    x1 = (x0+a/x0)/2;
    while(fabs(x1-x0)>=Epsilon){
        x0=x1;
        x1 = (x0+a/x0)/2;
    }
    printf("平方根：%.5f\n",x1);
    
    return 0;
}
