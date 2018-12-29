//
//  Three.m
//  Algorithm
//
//  Created by taoxiaofei on 2018/12/29.
//  Copyright © 2018年 easy. All rights reserved.
//

#import "Three.h"

@implementation Three
+ (NSDictionary *)calculate:(NSArray<NSNumber *> *)ary{
    NSDictionary *dic = [NSDictionary dictionary];
    NSInteger min = [ary[0] integerValue];
    NSInteger max = [ary[0] integerValue];
    if ([ary[1] integerValue] >= [ary[0] integerValue]) {
        max = [ary[1] integerValue];
    }else{
        min = [ary[1] integerValue];
    }
    
    for (NSInteger i = 2; i < ary.count; i++) {
        if ([ary[i] integerValue] < min) {
            min = [ary[i] integerValue];
        }else if([ary[i] integerValue] >= max){
            max = [ary[i] integerValue];
        }
    }
    
    dic = @{@"min":@(min),@"max":@(max)};
    return dic;
}
@end
