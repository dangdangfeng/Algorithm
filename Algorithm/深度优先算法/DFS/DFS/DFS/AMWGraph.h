

#import <Foundation/Foundation.h>

@interface AMWGraph : NSObject
@property (nonatomic, strong) NSMutableArray *edges;//邻接矩阵，用来存储边


//初始化矩阵，一维数组，和边的数目
- (instancetype)initWithN:(NSInteger)n;

//得到结点的个数
- (NSInteger)getNumOfVertex;

//得到边的数目
- (NSInteger)getNumOfEdges;

// 返回结点i的数据
- (id)getValueByIndex:(NSInteger)i;

//返回v1,v2的权值
- (NSInteger)getWeight:(NSInteger)v1 withV2:(NSInteger)v2;

//插入结点
- (void)insertVertex:(id)vertex;


- (void)insertEdge:(NSInteger)v1 withV2:(NSInteger)v2 withWeight:(NSInteger)weight;

//删除结点
- (void)deleteEdge:(NSInteger)v1 withV2:(NSInteger)v2;

//得到第一个邻接结点的下标
- (NSInteger)getFirstNeighbor:(NSInteger)index;

//根据前一个邻接结点的下标来取得下一个邻接结点
- (NSInteger)getNextNeighbor:(NSInteger)v1 withV2:(NSInteger)v2;

//对外公开函数，深度优先遍历，与其同名私有函数属于方法重载
- (void)depthFirstSearch:(NSMutableArray *)isVisited;

//对外公开函数，广度优先遍历
- (void)broadFirstSearch:(NSMutableArray *)isVisited;
@end


/****************************************
 无向图  对称矩阵
 
 V0--------V1
 |         /|
 |        / |
 |     V2   |
 |   /   \  |
 | /      \ |
 V3        V4
 
 0 1 0 1 0
 1 0 1 0 1
 0 1 0 1 1
 1 0 1 0 0
 0 1 1 0 0
 ******************************************/



/******************************************
有向图
 
 0 1 1 0
 0 0 0 0
 0 0 0 1
 1 0 0 0
 
 
 V0->V1
 V0->V2
 V2->V3
 V3->V0

 ******************************************/


/*********************************************
深度优先遍历:从初始点出发，不断向前走，如果碰到死路了，就往回走一步，尝试另一条路，直到发现了目标位置。这种不撞南墙不回头的方法，即使成功也不一定找到一条好路，但好处是需要记住的位置比较少。
 
广度优先:从初始点出发，把所有可能的路径都走一遍，如果里面没有目标位置，则尝试把所有两步能够到的位置都走一遍，看有没有目标位置；如果还不行，则尝试所有三步可以到的位置。这种方法，一定可以找到一条最短路径，但需要记忆的内容实在很多，要量力而行。

**********************************************/