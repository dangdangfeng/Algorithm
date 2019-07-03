#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int Find(int target, int array[3][5]);
int Find1(int target, int array[3][5]);

int main(int argc, char const *argv[])
{
    int numbers[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int x = Find(14,numbers);
    printf("x:%d \n",x);
  
    return 0;
}

int Find(int target, int array[3][5]){
    
    int l = sizeof(*array)/sizeof(**array);
    for (int i = 0; i < 3; i++)
    {
        printf("i:%d \n",i);
        int low = 0;
        int high = l - 1;
        while (low <= high)
        {
            int mid = (low + high)/2;
            if(target<array[i][mid]){
                high = mid - 1;
            }else if(target>array[i][mid]){
                low = mid + 1;
            }else{
                return 1;
            }
        }
    }
    return 0;
}

int Find1(int target, int array[3][5]){
    int len = 3-1;
    int i = 0;

    while ((len >= 0) && (i<5))
    {
        if(array[len][i] == target){
            return 1;
        }else if (array[len][i]<target)
        {
            i++;
        }else
        {
            len--;
        }
    }
    return 0;
    
}