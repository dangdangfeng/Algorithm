#include <stdio.h>
#include <stdlib.h>

int Delete(int a[], int *n, int i);

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,56};
    int *n = (int *)malloc(sizeof(int));
    *n = 5;
    int i = Delete(a,n,4);
    for(int j = 0; j < *n; j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n");
    
    return 0;
}

int Delete(int a[], int *n,int i){
    int j;
    if (i < 0 || i >= *n) {
        return 0;
    }
    for( j = i+1; j < *n; j++)
    {
        a[j-1] = a[j];
    }
    (*n)--;
    return 1;
}
