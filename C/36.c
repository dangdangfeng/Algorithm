#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int KeyType;

typedef struct 
{
    KeyType key;
}DataType;

void BubbleSort(DataType a[], int n){
    int i, j, flag = 1;
    DataType temp;

    for( i = 1; i < n && flag == 1; i++)
    {
        flag = 0;
        for( j = 0; j < n - i; j++)
        {
            if (a[j].key > a[j+1].key) {
                flag = 1;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
        }
        
    }
    
}

void QuickSort(DataType a[], int low, int high){
    int i= low, j = high;
    DataType temp = a[low];

    while(i < j){
        while(i < j && temp.key <= a[j].key){
            j--;
        }
        if (i < j) {
            a[i] = a[j];
            i++;
         }
        
        while(i < j && a[i].key < temp.key){
            i++;
        }
        if (i < j) {
            a[j] = a[i];
            j--;
        }
        
    }
    a[i] = temp;

    if (low < i) {
        QuickSort(a, low,i-1);
    }
    if (i < high) {
        QuickSort(a,j+1,high);
    }
}


int main(int argc, char const *argv[])
{
    // int a[] = {1, 2, 3, 7, 2, 1};
    // int len = sizeof(a) / sizeof(*a);
    // BubbleSort(a, len);
    // QuickSort(a,0,len-1);
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    // printf("\n");

    int i, n = 30000;
    double dif;
    time_t start,end;
    DataType test1[30000], test2[30000];

    for( i = 0; i < n; i++)
    {
        test1[i].key = rand();
        test2[i].key = test1[i].key;
    }
    
    time(&start);
    BubbleSort(test1,n);
    time(&end);
    dif = difftime(end,start);

    printf("冒泡排序: %.2f 秒\n",dif);

    time(&start);
    QuickSort(test2, 0,n-1);
    time(&end);
    dif = difftime(end, start);

    printf("快排排序: %.2f 秒\n", dif);

    return 0;
}


