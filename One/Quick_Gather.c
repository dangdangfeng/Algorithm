
/*当重复数值较多时，把与基准点相同的数据聚合在一起 ，不进行下一趟排序*/

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

void swap(int *arr, int firstIndex, int secondIndex)
{
    int tmp = arr[firstIndex];
    arr[firstIndex] = arr[secondIndex];
    arr[secondIndex] = tmp;
}

void gather(int arr[], int first, int end, int mid,int *left, int *right){
    if (first < end)
    {
        int count = mid - 1;
        for (int i = mid - 1; i >= first; i--)
        {
            if (arr[i] == arr[mid])
            {
                swap(arr, i, count);
                count --;
            }
            
        }
        *left = count;
        count = mid + 1;
        for (int i = mid + 1; i <= end; i++)
        {
            if (arr[i] == arr[mid])
            {
                swap(arr, i ,count);
                count++;
            }
            
        }
        *right = count;
        
        
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
        gather(arr, first, end, (first + end) / 2 + first,&arr[first],&arr[end]);
        int mid = PartSort(arr, first, end);
        Quick(arr, first, mid - 1);
        Quick(arr, mid + 1, end);
    }
}