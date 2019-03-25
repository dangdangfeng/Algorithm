/*
 实现将输入的字符串反序输出
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void reverse_str(char *str);

    int main(int argc, char const *argv[])
{
    char str[1024] = {};

    printf("请输入一行字符串：");
    fgets(str,1024,stdin);
    reverse_str(str);
    return 0;
}

void reverse_str(char * str){
    
    int length = strlen(str);
    for(length; length > 0; length--)
    {
        printf("%c",*(str+length-1));
    }
    printf("\n");
    
}