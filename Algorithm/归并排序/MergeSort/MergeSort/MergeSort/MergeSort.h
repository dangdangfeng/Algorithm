
#import <Foundation/Foundation.h>

@interface MergeSort : NSObject

+ (NSMutableArray *)mergeSort:(NSMutableArray *)ary withCapacity:(NSInteger)n;

@end


/****************************************
 
 归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将二个有序数列合并。
 这个非常简单，只要从比较二个数列的第一个数，谁小就先取谁，取了后就在对应数列中删除这个数。然后再进行比较，如果有数列为空，那直接将另一个数列的数据依次取出即可。
 合并有序数列的效率是比较高的，可以达到O(n).
 
 **************************************/