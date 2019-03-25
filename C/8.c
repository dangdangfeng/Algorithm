/*
题目：求s=a+aa+aaa+aaaa+aa…a的值，其中a是一个数字。例如
2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。

程序分析：关键是计算出每一项的值。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,n,count = 1;
    long int sn = 0,tn = 0;
    printf("please input a and n \n");
    scanf("%d %d",&a,&n);
    printf("a=%d,n=%d\n",a,n);
    while(count<=n){
        tn = tn + a;
        sn = sn + tn;
        a = a* 10;
        ++count;
    }
    printf("a+aa+...=%ld\n",sn);
    
    return 0;
}
