
#import "ShellSort.h"

@implementation ShellSort

+ (void)shellSort:(NSMutableArray *)list{
    int gap = [list count]/2.0;
    while (gap >= 1) {
        for (int i = gap ; i < [list count]; i++) {
            NSInteger temp = [[list objectAtIndex:i] integerValue];
            int j = i;
            while (j >= gap && temp < [[list objectAtIndex:(j-gap)] integerValue]) {
                [list replaceObjectAtIndex:j withObject:[list objectAtIndex:j-gap]];
                j-=gap;
            }
            [list replaceObjectAtIndex:j withObject:[NSNumber numberWithInteger:temp]];
        }
        gap = gap/2;
    }
}
@end
