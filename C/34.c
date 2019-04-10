#include <stdio.h>

void BubbleSort(int a[], int n);

    int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,7,2,1};
    int len = sizeof(a)/sizeof(*a);
    BubbleSort(a,len);
    for(int i = 0; i < len; i++)
    {
        printf("%d",a[i]);
    }

    printf("\n");
    
    return 0;
}

void BubbleSort(int a[], int n){
    int i , j , flag = 1;
    int temp;

    for( i = 0; i < n && flag == 1; i++)
    {
        flag = 0;
        for( j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j+1]) {
                flag = 1;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
        }
        
    }
    
}
