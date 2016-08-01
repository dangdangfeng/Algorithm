
#import "BinarySearch.h"

@implementation BinarySearch

+ (NSInteger)binarySearchNoRecursion:(NSArray *)srcArray withDes:(NSNumber *)des{
    NSInteger low = 0;
    NSInteger high = [srcArray count] - 1;
    while (low <= high) {
        NSInteger middle = low + ((high + low)>>1);//中间位置计算,low+ 最高位置减去最低位置,右移一位,相当于除2.也可以用(high+low)/2
        if ([des integerValue] == [srcArray[middle] integerValue]) return middle;
        else if([des integerValue] < [srcArray[middle] integerValue]) high = middle - 1;
        else low = middle + 1;
    }
    return -1;
}

+ (NSInteger)binarySearchWithRecursion:(NSArray *)srcArray withDes:(NSNumber *)des{
    NSInteger low = 0;
    NSInteger high = [srcArray count] - 1;
    return [self binSearch:srcArray withLow:low withHigh:high withKey:des];
}

+ (NSInteger)binSearch:(NSArray *)srcArray withLow:(NSInteger)low withHigh:(NSInteger)high withKey:(NSNumber *)key{
    if (low <= high) {
        NSInteger mid = (low + high)/2;
        if ([key integerValue] == [srcArray[mid] integerValue]) return mid;
        else if([key integerValue] < [srcArray[mid] integerValue]) return [self binSearch:srcArray withLow:low withHigh:(mid - 1) withKey:key];
        else return [self binSearch:srcArray withLow:mid+1 withHigh:high withKey:key];
    }else{
        return -1;
    }
}

@end
