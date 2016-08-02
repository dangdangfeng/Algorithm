
#import "AMWGraph.h"

@interface AMWGraph ()

@property (nonatomic, strong) NSMutableArray *vertexList;//存储点的链表

@property (nonatomic, assign) NSInteger numOfEdges;//边的数目

@end

@implementation AMWGraph

//初始化矩阵，一维数组，和边的数目
- (instancetype)initWithN:(NSInteger)n{
    if (self = [super init]) {
        _edges = [NSMutableArray array];
        _vertexList = [NSMutableArray arrayWithCapacity:n];
        _numOfEdges = 0;
    }
    return self;
}

//得到结点的个数
- (NSInteger)getNumOfVertex{
    return [self.vertexList count];
}

 //得到边的数目
- (NSInteger)getNumOfEdges{
    return self.numOfEdges;
}

// 返回结点i的数据
- (id)getValueByIndex:(NSInteger)i{
    return self.vertexList[i];
}

//返回v1,v2的权值
- (NSInteger)getWeight:(NSInteger)v1 withV2:(NSInteger)v2{
    return [self.edges[v1][v2] integerValue];
}

//插入结点
- (void)insertVertex:(id)vertex{
    [self.vertexList addObject:vertex];
}


- (void)insertEdge:(NSInteger)v1 withV2:(NSInteger)v2 withWeight:(NSInteger)weight{
    NSMutableArray *ary1 = [_edges objectAtIndex:v1];
    ary1[v2] = [NSNumber numberWithInteger:weight];
    self.numOfEdges++;
}

//删除结点
- (void)deleteEdge:(NSInteger)v1 withV2:(NSInteger)v2{
    self.edges[v1][v2] = [NSNumber numberWithInt:0];
    self.numOfEdges--;
}

//得到第一个邻接结点的下标
- (NSInteger)getFirstNeighbor:(NSInteger)index{
    for (NSInteger j = 0; j < [_vertexList count]; j++) {
        if ([_edges[index][j] intValue] > 0) return j;
    }
    return -1;
}

//根据前一个邻接结点的下标来取得下一个邻接结点
- (NSInteger)getNextNeighbor:(NSInteger)v1 withV2:(NSInteger)v2{
    for (NSInteger j = v2+1; j<[_vertexList count]; j++) {
        if ([_edges[v1][j] intValue]>0) {
            return j;
        }
    }
    return -1;
}

//私有函数，深度优先遍历
- (void)depthFirstSearch:(NSMutableArray *)isVisited withI:(NSInteger)i{
    NSLog(@"%@",[self getValueByIndex:i]);
    
    isVisited[i] = [NSNumber numberWithBool:YES];
    
    NSInteger w = [self getFirstNeighbor:i];
    while (w!=-1) {
        if ([isVisited[w] compare:@(0)] == NSOrderedSame) {
            [self depthFirstSearch:isVisited withI:w];
        }
        w = [self getNextNeighbor:i withV2:w];
    }
}

 //对外公开函数，深度优先遍历，与其同名私有函数属于方法重载
- (void)depthFirstSearch:(NSMutableArray *)isVisited{
    for (NSInteger i = 0; i < [self getNumOfVertex]; i++) {
        if ([isVisited[i] compare:@(0)] == NSOrderedSame) {
            [self depthFirstSearch:isVisited withI:i];
        }
    }
}

//私有函数，广度优先遍历
- (void)broadFirstSearch:(NSMutableArray *)isVisited withI:(NSInteger)i{
    NSInteger u,w;
    NSMutableArray *queue = [NSMutableArray array];
    //访问结点i
    NSLog(@"%@",[self getValueByIndex:i]);
    isVisited[i] = [NSNumber numberWithBool:YES];
    //结点入队列
    [queue addObject:[NSNumber numberWithInteger:i]];
    while ([queue count] > 0) {
        u = [queue[0] integerValue];
        [queue removeObjectAtIndex:0];
        w = [self getFirstNeighbor:u];
        while (w!=-1) {
            if ([isVisited[w] compare:@(0)] == NSOrderedSame) {
                NSLog(@"%@",[self getValueByIndex:w]);
                isVisited[w] = [NSNumber numberWithBool:YES];
                [queue addObject:[NSNumber numberWithInteger:w]];
            }
            w = [self getNextNeighbor:u withV2:w];
        }
    }
}

//对外公开函数，广度优先遍历
- (void)broadFirstSearch:(NSMutableArray *)isVisited{
    for (int i = 0; i < [self getNumOfVertex]; i++) {
        if ([isVisited[i] compare:@(0)] == NSOrderedSame) {
            [self broadFirstSearch:isVisited withI:i];
        }
    }
}
@end
