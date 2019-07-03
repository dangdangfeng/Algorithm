/*三分取中法。对基准数的选取进行优化，取首元素，中间元素和尾元素进行比较，取三个中中间值作为基准值。这样分割数组时就可以有效的分为等长数组。*/
#include <stdio.h>

void swap(int arr[], int firstIndex, int secondIndex);
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

void FindSecondMax(int arr[], int first, int end, int mid){
    if (arr[end] < arr[mid])
    {
        swap(arr,mid,end);
    }
    if (arr[first] < arr[mid])
    {
        swap(arr,mid,first);
    }
    if (arr[first] < arr[end])
    {
        swap(arr,end,first);
    }
}

void swap(int *arr, int firstIndex, int secondIndex){
    int tmp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = tmp;
}

int PartSort(int *arr,int first, int end){
    int tmp = arr[first];
    while (first != end)
    {
        while(first < end && arr[end] >= tmp){
            end --;
        }
        arr[first] = arr[end];
        while(first < end && arr[first] <= tmp){
            first ++;
        }
        arr[end] = arr[first];
    }
    arr[first] = tmp;
    return first;
}

void Quick(int *arr,int first, int end){
    if (first < end)        
    {
        FindSecondMax(arr,first,end,(first+end)/2+first);
        int mid = PartSort(arr, first, end);
        Quick(arr,first,mid-1);
        Quick(arr,mid+1,end);
    }
}