//
//  Three.h
//  Algorithm
//
//  Created by taoxiaofei on 2018/12/29.
//  Copyright © 2018年 easy. All rights reserved.
//  寻找数组中的最大值和最小值

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Three : NSObject
+ (NSDictionary *)calculate:(NSArray<NSNumber *> *)ary;
@end

NS_ASSUME_NONNULL_END

/*
 解法一：分别求最大和最小值
 
 　　可以分别求出数组的最大值和最小值，这样，我们需要比较2N次才能求解。
 
 解法二：分组求解
 
 　　(1) 按顺序将数组中相邻的两个数分在同一组；
 
 　　(2) 比较同一组的两个数，将大的数放在偶数位上，小的放在奇数位上；
 
 　　(3) 最后，从偶数位上求最大值，奇数位上求最小值即可。
 
 　　一共需要比较1.5N次。这种办法虽然比较次数变少了，但却破坏了原数组。
 
 解法三：改进的分组
 
 　　(1) 用两个变量max和min分别存储当前的最大值和最小值。
 
 　　(2) 同一组的两个数比较完之后，不再调整顺序，将其中较大的与当前max比较，较小的与min比较；
 
 　　(3) 如此反复，直到遍历完整个数组。
 
 　　整个过程比较次数为1.5N次。
 
 解法四：分治策略
 
 　　分别求出前后N/2个数的min和max，然后，取较小的min，较大的max即可。
 
 　　需要比较的次数为1.5N-2，分析略。
 */
