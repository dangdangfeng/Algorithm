/*
题目5：利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60
-89分之间的用B表示，60分以下的用C表示。

程序分析：(a>b)?a:b这是条件运算符的基本例子。
*/

int main(int argc, char const *argv[])
{
    int score;
    char grade;
    printf("please input a score\n");
    scanf("%d",&score);
    grade=score>=90?'A':score>=60?'B':'C';
    printf("%d belongs to %c\n",score,grade);
    return 0;
}
