#include <stdio.h>

void Reverse(int a[], int n, int b[]);
void Reverse1(int a[], int n);

    int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6};
    int len = sizeof(a)/sizeof(*a);
    int b[len];

    Reverse(a,len, b);
    Reverse1(a, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d",b[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d", a[i]);
    }

    printf("\n");
    return 0;
}

void Reverse(int a[], int n,int b[]){
    int i;
    for( i = 0; i < n; i++)
    {
        b[i] = a[n - 1 -i];
    }
    
}

void Reverse1(int a[],int n){
    int i, m = n/2;
    int temp;
    for( i = 0; i < m; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 -i] = temp;
    }
    
}