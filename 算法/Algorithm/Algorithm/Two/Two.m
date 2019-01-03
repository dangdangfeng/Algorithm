//
//  Two.m
//  Algorithm
//
//  Created by taoxiaofei on 2018/12/28.
//  Copyright © 2018年 easy. All rights reserved.
//  找出数组中重复的数字

#import "Two.h"

@implementation Two

+ (NSInteger)calculate1:(NSArray<NSNumber *> *)ary{
    __block NSInteger res = NSIntegerMax;
    for (NSNumber *i in ary) {
        [ary enumerateObjectsUsingBlock:^(NSNumber * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if (i.integerValue == [obj integerValue]) {
                res = i.integerValue;
                *stop = YES;
            }
        }];
    }
    
    return res;
}

+ (NSInteger)calculate2:(NSArray<NSNumber *> *)ary{
    __block NSInteger res = NSIntegerMax;
    __block NSMutableDictionary *mDic = [NSMutableDictionary dictionaryWithCapacity:ary.count];
    [ary enumerateObjectsUsingBlock:^(NSNumber * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([mDic.allKeys containsObject:obj]) {
            res = [obj integerValue];
            *stop = YES;
        }
        [mDic addEntriesFromDictionary:@{obj:@1}];
    }];
    return res;
}

+ (NSInteger)calculate3:(NSArray<NSNumber *> *)ary{
    NSInteger res = NSIntegerMax;
    NSInteger i=0;
    NSMutableArray *mAry = [NSMutableArray arrayWithArray:ary];
    while ((mAry[i]>=0)&&(i < mAry.count)){
        while ([mAry[i] integerValue] != i)
        {
            if ([mAry[i] integerValue] == [mAry[[mAry[i] integerValue]] integerValue])
            {
                res = [mAry[i] integerValue];
                return res;
            }
            else
            {
                NSNumber *current = mAry[i];
                NSNumber *next = mAry[[mAry[i] integerValue]];
                [mAry replaceObjectAtIndex:i withObject:next];
                [mAry replaceObjectAtIndex:[mAry[i] integerValue] withObject:current];
            }
        }
        i++;
    }
    return res;
}

@end
