#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[10] = {4,5,2,10,7,1,8,3,6,9};
    int i,j,temp,isSorted;

    for ( i = 0; i < 10-1; i++)
    {
        isSorted = 1;
        for ( j = 0; j < 10-1-i; j++)
        {
            if (nums[j] > nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            break;
        }
        
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

