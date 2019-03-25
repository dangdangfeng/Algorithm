/*
题目：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，
则继续判断第二个字母。

程序分析：用情况语句比较好，如果第一个字母一样，则判断用情况语句或if语
句判断第二个字母。
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char letter;
    printf("please input the first letter of someday\n");
    while((letter=getchar())!='Y'){
        switch(letter){
            case 'S':printf("please input second letter\n");
            if ((letter=getchar())=='a') {
                printf("saturday\n");
            }else if ((letter=getchar())=='u')
            {
                printf("sunday\n");
            }else
            {
                printf("data error\n");
            }
            break;
            case 'F':
                printf("friday\n");
                break;
            case 'M':
                printf("Monday\n");
                break;
            case 'T':printf("please input second letter\n");
                if ((letter=getchar())=='u') {
                    printf("tuesday\n");
                }else if ((letter=getchar())=='h')
                {
                    printf("thursday\n");
                }else
                {
                    printf("data error\n");
                }
                
                break;
            case 'W':
                printf("Wednesday\n");
                break;
            default:
                printf("data error\n");
                break;
        }
    }
    
    return 0;
}
