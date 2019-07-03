#include <stdio.h>
#include <time.h>

void Quick(int *arr, int first, int end);

int main(int argc, char const *argv[])
{
    int arr[10] = {10,58,36,1,45,64,14,200,11,69};

    int len = sizeof(arr)/sizeof(arr[0]);
    time_t start, end;
    start=clock();
    Quick(arr,0,len-1);
    end=clock();
    int i = 0;
    for(;i<len;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
    return 0;
}

int PartSort(int *arr, int first, int end)
{
    int tmp = arr[first];
    while (first != end)
    {
        while(first<end && arr[end]>=tmp){
            end--;
        }
        arr[first]=arr[end];
        while(first<end && arr[first]<=tmp){
            first++;
        }
        arr[end]=arr[first];
    }
    arr[first] = tmp;
    return first;
    
}

void Quick(int *arr, int first,int end){
    if (first < end)
    {
        int mid = PartSort(arr,first,end);
        Quick(arr,first,mid-1);
        Quick(arr,mid+1,end);
    }
    
}