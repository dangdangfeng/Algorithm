/*
题目：输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数
。

程序分析：利用while语句,条件为输入的字符不为’\n’.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    int letters = 0, space = 0,digit = 0,others = 0;
    printf("please input some characters\n");
    while((c = getchar())!='\n'){
        if (c>='a'&&c<='z'||c>='A'&&c<='Z') {
            letters++;
        }else if(c==' ')
        {
            space++;
        }else if(c>='0'&&c<='9')
        {
            digit++;
        }else
        {
            others++;
        } 
    }
    printf("all in all : char=%d space=%d digit=%d others=%d\n",letters,space,digit,others);
    
    return 0;
}
