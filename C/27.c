/*
 *给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 *你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

时间复杂度：O(n^2)， 对于每个元素，我们试图通过遍历数组的其余部分来寻找它所对应的目标元素，这将耗费 O(n)O(n)O(n) 的时间。因此时间复杂度为 O(n2)O(n^2)O(n2)。

空间复杂度：O(1)
*/

#include <stdio.h>

int *twoSum(int *nums, int numsSize, int target);

int main(int argc, char const *argv[])
{
    int nums[] = {3,2,3};
    int count = sizeof(nums) / sizeof(*nums);
    int target = 6;
    int *indexes = twoSum(nums,count,target);
    if (indexes != NULL) {
        printf("%d %d \n",indexes[0], indexes[1]);
    }else{
        printf("Not Found\n");
    }
    
    return 0;
}

int * twoSum(int * nums, int numsSize,int target)
{
    static int a[2] = {0};

    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                return a;
            }
            
        }
        
    }
    return NULL;
    
}
