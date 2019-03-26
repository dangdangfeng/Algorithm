/*
输入三个整数x,y,z，请把这三个数由小到大输出。

程序分析：我们想办法把最小的数放到x上，先将x与y进行比较，如果x>y则将x与y的值进行交换，然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。
*/

#include <stdio.h>

#define N 3 

int main(int argc, char const *argv[])
{
    int arr[N];
    int temp;
    int i,j;

    printf("enter %d number:\n",N);
    for(i = 0; i < N;i++){
        scanf("%d",&arr[i]);
    }

    for(i = 0; i < N-1;i++){
        for(j=0;j<N-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("the arr is :");
    for(i = 0; i < N;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    return 0;
}
