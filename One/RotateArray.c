#include <stdlib.h>
#include <stdio.h>

int MinInOrder(int numbers[], int index1, int index2);

int Min(int numbers[], int length)
{
    if(numbers == NULL || length <= 0)
        return -1;
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    
    while (numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 <= 1){
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2)/2;

        if (numbers[index1] ==  numbers[index2] && numbers[indexMid]==numbers[index1])
        {
            return MinInOrder(numbers,index1,index2);
        }
        
        if (numbers[indexMid] >= numbers[index1])
        {
            index1 = indexMid;
        }else if(numbers[indexMid] <= numbers[index2])
        {
            index2 = indexMid;
        }
    }
    return numbers[indexMid];
    
}

// 顺序查找
int MinInOrder(int numbers[], int index1 , int index2){
    int result = numbers[index1];
    for (int i = index1+1; i <= index2; i++)
    {
        if (result > numbers[i])
        {
            result = numbers[i];
        }
        
    }
    return result;
    
}

int main(int argc, char const *argv[])
{
    int numers[] = {3,4,5,1,2};
    int len = sizeof(numers)/sizeof(*numers);
    int i = Min(numers,len);
    printf("%d \n",i);
    return 0;
}
