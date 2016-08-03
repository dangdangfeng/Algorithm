#import "DynamicProgramming.h"

@implementation DynamicProgramming
+ (NSString *)getRandomString:(NSInteger)length{
    NSString *str = @"abcdefghijklmnopqrstuvwxyz";
    NSMutableString *res = [[NSMutableString alloc] initWithCapacity:length];
    for (int i = 0; i < length; i++) {
        NSRange range;
        range.length = 1;
        range.location = arc4random()%length;
        NSString *r = [str substringWithRange:range];
        [res appendString:r];
    }
    return res;
}

+ (NSString *)lcs:(NSString *)str1 withOtherString:(NSString *)str2{
    int length1 = (int)[str1 length];
    int length2 = (int)[str2 length];
    NSMutableArray *p1 = [NSMutableArray arrayWithCapacity:length2 + 1];
    // 构造二维数组记录子问题x[i]和y[i]的LCS的长度
    NSMutableArray *opt = [NSMutableArray arrayWithCapacity:length1 + 1];
    for (int i = 0; i < length2 + 1; i++) {
        [p1 addObject:@0];
    }
    
    for (int i = 0; i < length1 + 1; i++) {
        [opt addObject:p1];
    }
    

    
    for (int i = length1 - 1; i >= 0; i--) {
        for (int j = length2 - 1; j >= 0; j--) {
            NSRange range1 = {i,1};
            NSRange range2 = {j,1};
            if ([[str1 substringWithRange:range1] isEqualToString:[str2 substringWithRange:range2]]) {
                opt[i][j] = @([opt[i+1][j+1] integerValue] + 1);
            }else{
                int i1 = [opt[i+1][j] intValue] , i2 = [opt[i][j+1] intValue];
                opt[i][j] = @(MAX(i1,i2));
            }
        }
    }
 
    int i = 0,j = 0;
    NSMutableString *result = [[NSMutableString alloc] init];
    
    while (i < length1 && j < length2) {
        NSRange range1 = {i,1};
        NSRange range2 = {j,1};
        if ([[str1 substringWithRange:range1] isEqualToString:[str2 substringWithRange:range2]]) {
            [result appendString:[str1 substringWithRange:range1]];
            i++;
            j++;
        }else if([opt[i + 1][j] intValue] >= [opt[i][j + 1] intValue]){
            i++;
        }else{
            j++;
        }
    }
    return result;
}


@end
