//
//  One.m
//  Algorithm
//
//  Created by taoxiaofei on 2018/12/28.
//  Copyright © 2018年 easy. All rights reserved.
//  每天一道LeetCode-----找到由连续数字组成的数组中缺失的那个连续值

#import "One.h"

@implementation One
+ (NSInteger)calculate:(NSArray *)ary{
    
    __block NSInteger sum = 0;
    [ary enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        sum += [obj integerValue];
    }];
    NSInteger n = ary.count+1;
    return n*(n + 1)/2 - sum;
}

@end
