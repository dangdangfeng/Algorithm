
#import <Foundation/Foundation.h>

@interface BinarySearch : NSObject

/// 递归
+ (NSInteger)binarySearchWithRecursion:(NSArray *)srcArray withDes:(NSNumber *)des;

/// 非递归
+ (NSInteger)binarySearchNoRecursion:(NSArray *)srcArray withDes:(NSNumber *)des;
@end
