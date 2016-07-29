
#import "HeapSort.h"

@implementation HeapSort

/// 最大堆heap  最大／最小优先级队列
+ (void)createBiggestHeap:(NSMutableArray *)list withSize:(int)size beIndex:(int)element{
    int lchild = element * 2 + 1,rchild = lchild + 1;
    while (rchild < size) {
        if (list[element] <= list[lchild] && list[element] <= list[rchild]) return;
    }
    
    
    
    
    
    int lastParentIndex = (p - 1)/2.0;
    for (int i = lastParentIndex; i >= 0; i--) {
        NSInteger parentIndex = i;
        NSInteger parentNode = [[list objectAtIndex:parentIndex] integerValue];
        
        int currentChildIndex = 2*i + 1;
        while (currentChildIndex <= p - 1) {
            NSInteger leftChildNode = [[list objectAtIndex:currentChildIndex] integerValue];
            if (currentChildIndex + 1 <= p - 1) {
                int rightChildIndex = currentChildIndex + 1;
                NSInteger rightChildNode = [[list objectAtIndex:rightChildIndex] integerValue];
                
                if (rightChildNode > leftChildNode && rightChildNode > parentNode) {
                    [list exchangeObjectAtIndex:parentIndex withObjectAtIndex:rightChildIndex];
                    currentChildIndex = rightChildIndex;
                }else if (leftChildNode > rightChildNode && leftChildNode > parentNode){
                    [list exchangeObjectAtIndex:parentIndex withObjectAtIndex:currentChildIndex];
                }else{
                    if (leftChildNode > parentNode) {
                        [list exchangeObjectAtIndex:parentIndex withObjectAtIndex:currentChildIndex];
                    }
                }
                parentIndex = currentChildIndex;
                currentChildIndex = 2*currentChildIndex + 1;
            }
        }
    }
}

+ (void)heapSort:(NSMutableArray *)list{
    int i , size;
    size = [list count]/1.0;
    for (i = [list count]/1.0 - 1; i >= 0; i--) {
        [self createBiggestHeap:list withSize:size beIndex:i];
    }
    while (size > 0) {
        [list exchangeObjectAtIndex:size - 1 withObjectAtIndex:0];
        size--;
        [self createBiggestHeap:list withSize:size beIndex:0];
    }
}

@end
