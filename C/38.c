#include <stdio.h>
#include <stdlib.h>

// 插入排序

void insertion_sort(char s[], int n);

    int main(int argc, char const *argv[])
{
    return 0;
}

void swap(char *x, char *y){
    char *temp;
    temp = x;
    x = y;
    y = temp;
}

void insertion_sort(char s[], int n)
{
    int i, j;
    for ( i = 0; i < n; i++)
    {
        j = i;
        while ((j > 0) && (s[j] < s[j - 1]))
        {
            swap(&s[j],&s[j - 1]);
            j = j - 1;
        }
        
    }
    
}