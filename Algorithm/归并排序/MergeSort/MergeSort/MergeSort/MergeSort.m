
#import "MergeSort.h"

@implementation MergeSort

+ (void)mergearray:(NSMutableArray *)ary withFirst:(NSInteger)first withMid:(NSInteger)mid withLast:(NSInteger)last ResultAry:(NSMutableArray *)temp{
    NSInteger i = first, j = mid + 1;
    NSInteger m = mid ,n = last;
    NSInteger k = 0;
    
    while (i <= m && j <= n) {
        if (ary[i] <= ary[j])  temp[k++] = ary[i++];
        else temp[k++] = ary[j++];
    }
    
    while (i <= m) temp[k++] = ary[i++];
    
    while (j <= n) temp[k++] = ary[j++];
    
    for (i = 0; i < k; i++) ary[first + i] = temp[i];
}

+ (void)mergeSort:(NSMutableArray *)ary withFirst:(NSInteger)first withLast:(NSInteger)last ResultAry:(NSMutableArray *)temp{
    if (first < last) {
        NSInteger mid = (first + last) / 2;
        [self mergeSort:ary withFirst:first withLast:mid ResultAry:temp]; // 左边有序
        [self mergeSort:ary withFirst:mid + 1 withLast:last ResultAry:temp]; // 右边有序
        [self mergearray:ary withFirst:first withMid:mid withLast:last ResultAry:temp];// 将二个有序数列合并
    }
}

+ (NSMutableArray *)mergeSort:(NSMutableArray *)ary withCapacity:(NSInteger)n{
    NSMutableArray *p = [NSMutableArray arrayWithCapacity:n];
    [self mergeSort:ary withFirst:0 withLast:n-1 ResultAry:p];
    return p;
}

@end
