//
//  main.m
//  Algorithm
//
//  Created by taoxiaofei on 2018/12/28.
//  Copyright © 2018年 easy. All rights reserved.
//

#include <iostream>
#include <stdbool.h>

using namespace std;

int partition1(int arr[],int start, int end,int pivotIndex){
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex],arr[end]);
    int storeIndex = start;
    
    for (int i = start; i < end; ++i) {
        if (arr[i] <  pivot) {
            swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }
    swap(arr[storeIndex], arr[end]);
    return storeIndex;
}

void sort1(int arr[],int lo, int hi){
    if (lo >= hi) {
        return;
    }
    int index = partition1(arr, lo, hi, lo);
    sort1(arr, lo, index-1);
    sort1(arr, index+1, hi);
}

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";

    int arr[] = {12,30,15,16,2,6,8,10};
    
    sort1(arr, 0, 7);
    
    for (int i = 0; i < 8; i++) {
        printf("%i,",arr[i]);
    }
    
    return 0;
}


