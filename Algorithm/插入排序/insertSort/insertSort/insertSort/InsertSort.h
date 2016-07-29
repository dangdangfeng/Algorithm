
#import <Foundation/Foundation.h>

@interface InsertSort : NSObject

/// 直接插入排序
+ (void)insertSort:(NSMutableArray *)list;

/// 折半插入排序
+ (void)binaryInsertSort:(NSMutableArray *)list;
@end
