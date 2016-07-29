
#import "BubbleSort.h"

@implementation BubbleSort

+ (void)bubbleSortWithArray:(NSMutableArray *)array{
    
    for (int i = 0; i < array.count; i++) {
        for (int j = 0; j < array.count - i - 1; j++) {
            if (array[j] < array[j+1]) {
                int temp = [array[j] intValue];
                array[j] = array[j + 1];
                array[j + 1] = [NSNumber numberWithInt:temp];
            }
        }
    }
}

@end
