
#import "Dijkstra.h"

@implementation Dijkstra

+ (NSArray *)dijkstra_alg:(NSMutableArray *)map  withShotest:(NSMutableArray *)shortest withV:(NSMutableArray *)visited withO:(NSInteger)orig{
    
    NSInteger n = [shortest count];
    if ( n - 1 <= 0) return nil;
    
    // 初始化，第一个顶点求出
    shortest[orig] = @(0);
    visited[orig] = @(YES);

     // 要加入n-1个顶点
    for (int p = 0; p != n - 1; p++) {
        // 选出一个距离初始顶点最近的未标记顶点
        int k = -1;
        int min = -1;
        for (int i = 0; i < n; i++) {
            if ([visited[i] compare:@(0)] == NSOrderedSame && [map[orig][i] intValue] != -1) {
                if (min == -1 || min > [map[orig][i] intValue]) {
                   
                    min = [map[orig][i] intValue];
                    k = i;
                }
            }
        }
        // 正确的图生成的矩阵不可能出现K == M的情况
        if (k == -1) {
            NSLog(@"the input map matrix is wrong!");
            return nil;
        }
        
        shortest[k] = @(min);
        visited[k] = @(YES);
        
        for (int i = 0; i < n; i++) {
            
            
            if ([visited[i] compare:@(0)] == NSOrderedSame && [map[k][i] intValue] != -1) {
                int callen = min + [map[k][i] intValue];
                if ([map[orig][i] intValue] == -1 || [map[orig][i] intValue] > callen) {
                    map[orig][i] = @(callen);
                }
            }
        }
    }
    return shortest;
}

+(NSArray *)dijkstra:(NSMutableArray *)map withOrig:(NSInteger)orig{
    NSInteger n = [map count];
    NSMutableArray *shortest = [NSMutableArray arrayWithCapacity:n];
    NSMutableArray *visited = [NSMutableArray arrayWithCapacity:n];
    for (int i = 0; i < n; i++) {
        [shortest addObject:@(-1)];
        [visited addObject:@(NO)];
    }
    return [self dijkstra_alg:map withShotest:shortest withV:visited withO:orig];
}

@end
