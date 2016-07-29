
#import "QuickSort.h"

@implementation QuickSort

+ (void)quickSortWithArray:(NSMutableArray *)array withLeft:(NSInteger)left andRight:(NSInteger)right{
    if (left >= right) return;
    
    NSInteger i = left;
    NSInteger j = right;
    NSInteger key = [array[left] integerValue];
    
    while (i < j) {
        while (i < j && key <= [array[j] integerValue]) {
            j--;
        }
        array[i] = array[j];
        while (i < j && key >= [array[i] integerValue]) {
            i++;
        }
        array[j] = array[i];
    }
    array[i] = [NSNumber numberWithInteger:key];
    
    [[self class] quickSortWithArray:array withLeft:left andRight:i - 1];
    [[self class] quickSortWithArray:array withLeft:i + 1 andRight:right];
}

@end
