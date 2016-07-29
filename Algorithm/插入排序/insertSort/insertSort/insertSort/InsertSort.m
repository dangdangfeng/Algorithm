
#import "InsertSort.h"

@implementation InsertSort

+ (void)insertSort:(NSMutableArray *)list{
    for (int i = 1; i < [list count]; i++) {
        int j = i;
        NSInteger temp = [[list objectAtIndex:i] integerValue];
        while (j >0 && temp < [[list objectAtIndex:j - 1] integerValue]) {
            [list replaceObjectAtIndex:j withObject:[list objectAtIndex:(j - 1)]];
            j--;
        }
        [list replaceObjectAtIndex:j withObject:[NSNumber numberWithInteger:temp]];
    }
}

+ (void)binaryInsertSort:(NSMutableArray *)list{
    for (int i = 1; i < [list count]; i++) {
        NSInteger temp = [[list objectAtIndex:i] integerValue];
        int left = 0;
        int right = i - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (temp < [[list objectAtIndex:middle] integerValue]) {
                right = middle - 1;
            }else{
                left = middle + 1;
            }
        }
        for (int j = i; j > left; j--) {
            [list replaceObjectAtIndex:j withObject:[list objectAtIndex:j-1]];
        }
        [list replaceObjectAtIndex:left withObject:[NSNumber numberWithInteger:temp]];
    }
}

@end
