/*数据量较小时使用直接插入排序时间复杂度会小一些为O(n)*/
#include <stdio.h>

void Quick(int *arr, int first, int end);

    int main(int argc, char const *argv[])
{
    int arr[10] = {10, 58, 36, 1, 45, 64, 14, 200, 11, 69};

    int len = sizeof(arr) / sizeof(arr[0]);
    Quick(arr, 0, len - 1);
    int i = 0;
    for (; i < len; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}

void selectSort(int arr[], int len){
    int i,j;
    int min;
    int tmp;
    for ( i = 0; i < len - 1; i++)
    {
        min = i;
        for ( j = i+1; j < len; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            } 
        }
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
        
    }
    
}

int PartSort(int *arr, int first, int end)
{
    int tmp = arr[first];
    while (first != end)
    {
        while (first < end && arr[end] >= tmp)
        {
            end--;
        }
        arr[first] = arr[end];
        while (first < end && arr[first] <= tmp)
        {
            first++;
        }
        arr[end] = arr[first];
    }
    arr[first] = tmp;
    return first;
}

void Quick(int *arr, int first, int end)
{
    if (first < end)
    {
        selectSort(arr, end);
        int mid = PartSort(arr, first, end);
        Quick(arr, first, mid - 1);
        Quick(arr, mid + 1, end);
    }
}
