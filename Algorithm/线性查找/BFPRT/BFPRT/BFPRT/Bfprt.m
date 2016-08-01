
#import "Bfprt.h"

@implementation Bfprt

/// 冒泡排序
+ (void)bubbleSortWithArray:(NSMutableArray *)array withFirst:(NSInteger)first withEnd:(NSInteger)end{
    for (NSInteger i = first ; i < end; i++) {
        for (NSInteger j = end; j > i; j--) {
            if (array[j] < array[j-1]) {
                id temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

+ (void)bubbleSortWithArray:(NSMutableArray *)array{
    return [self bubbleSortWithArray:array withFirst:0 withEnd:[array count] - 1];
}


//求取最小的k个数
//数组a中从a[p]到a[r]的元素按照x划分,大于或者等于x的在右边,小于x的在左边
+ (NSInteger)partitionModify:(NSMutableArray *)a withP:(NSInteger)p withR:(NSInteger)r withX:(NSInteger)x{
    NSInteger i,j;
    
    j = r;
    
    for (i = p; i < j; i++) {
        if ([a[i] integerValue] >= x) {
            while (i<j && [a[j] integerValue] >= x) j--;
            if (i != j) {
                id t = a[i];
                a[i] = a[j];
                a[j] = t;
                j--;
            }
            else break;
        }
    }
    
    /*上面的循环结束分为几种情况
     1 i > j 此时必定有 a[i] >= x，否则 a[j+1] = a[i] < x 与 a[j+1] >= x 矛盾 ,如果不是边界，进入if语句
     2 i = j 此时如果 a[i] < x 则a[i+1] = a[j+1] >x 返回 i
     3 当i==p,此时直接返回边界元素下标
     4 当i == r,此时为右边界，此时a[i]肯定为x，返回i - 1，也即r - 1
     */
    
    if ([a[i] integerValue] >= x && i > p) {
        return i - 1;
    }
    return i;
}

//将r-p+1个数据按五个元素分为一组，分别找出各组的中位数，
//再将各组的中位数与数组开头的数据在组的顺序依次交换，对这些各组的中位数
//按同样的方法继续求出中位数，最后得出的整个数组的中位数，利用中位数就可以将数据按照与中位数的比较来划分
+ (NSInteger)selectModify:(NSMutableArray *)array withP:(NSInteger)p withR:(NSInteger)r withK:(NSInteger)k{
    NSInteger i;
    if (r - p + 1 <= 5) {
        [self bubbleSortWithArray:array withFirst:p withEnd:r];
        return [array[p + k - 1] integerValue];
    }
    
    //将r-p+1个数据按五个元素分为一组，可以分为(r - p + 1) / 5组
    //分别找出各组的中位数，再将各组的中位数与数组开头的数据按组的顺序依次交换
    for (i = 0; i < (r-p+1)/5;i++ ) {
        NSInteger s = p + 5*i,t=s+4;
        [self bubbleSortWithArray:array withFirst:s withEnd:t];
        id temp = array[p + i];
        array[p + i] = array[s + 2];
        array[s + 2] = temp;
    }
    //对这些各组的中位数
    //按同样的方法继续求出中位数，最后得出的整个数组的中位数 x
    NSInteger x = [self selectModify:array withP:p withR: p + (r - p + 1) / 5 - 1 withK:(r - p + 6) / 10];
    
    i = [self partitionModify:array withP:p withR:r withX:x];
    
    NSInteger j = i - p + 1;
    
    if (k <= j) {
        return [self selectModify:array withP:p withR:i withK:k];
    }else{
        return [self selectModify:array withP:i+1 withR:r withK:k-j];
    }
}


+ (NSInteger)selectModify:(NSMutableArray *)array withNum:(NSInteger)n{
    if (n == 0 || n > [array count]) return -1;// 未查到
    
    return [self selectModify:array withP:0 withR:[array count] - 1 withK:n];
}
@end
