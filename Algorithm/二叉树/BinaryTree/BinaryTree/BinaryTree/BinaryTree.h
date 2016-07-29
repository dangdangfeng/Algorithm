
//  二叉树一些方法

/**************************使用测试*****************************
 NSArray *arr = @[@4,@2,@7,@1,@3,@6,@9];
 BinaryTreeNode *node = [BinaryTree createTreeWithValues:arr];
 NSLog(@"%@",node);
 BinaryTreeNode *overNode = [BinaryTree invertBinaryTree:node];
 NSLog(@"%@",overNode);
 **************************************************************/

#import <Foundation/Foundation.h>

@class BinaryTreeNode;

@interface BinaryTree : NSObject

///创建二叉树
+ (BinaryTreeNode *)createTreeWithValues:(NSArray *)values;

/// 反转二叉树
+ (BinaryTreeNode *)invertBinaryTree:(BinaryTreeNode *)rootNode;

/// 反转二叉树(非递归)
+ (BinaryTreeNode *)invertBinaryTreeWithoutRecursion:(BinaryTreeNode *)rootNode;

/// 二叉树深度
+ (NSInteger)depathOfTree:(BinaryTreeNode *)rootNode;

/// 二叉树所有节点数  节点数=左子树节点数+右子树节点数+1（根节点）
+ (NSInteger)numberOfNodesInTree:(BinaryTreeNode *)rootNode;

//二叉树中某个节点到根节点的路径
+ (NSArray *)pathOfTreeNode:(BinaryTreeNode *)treeNode inTree:(BinaryTreeNode *)rootNode;

/// 先序遍历
//http://baike.baidu.com/link?url=rODMnACQtOHoi2j-w8riDGKfT1exqmaD9aMo1Mq9ECAZWnEuSr3oI3MAH5i2tLBx6GjYCCfMpELgiXMaXQFW5_
+ (void)treeFirstInformationWithNode:(BinaryTreeNode *)rootNode resultBlock:(void (^)(NSInteger value))block;

/// 中序遍历
//http://baike.baidu.com/link?url=98LrnOmbH7lUzt-kde2L4-aRuISGpg0he4XOiEl3OxqO9tzwL8oGFOrIdiQP4s_DmLAk3woPAaMAbOBO2qQ9Va
+ (void)treeMiddleInformationWithNode:(BinaryTreeNode *)rootNode resultBlock:(void (^)(NSInteger value))block;

/// 后序遍历
//http://baike.baidu.com/link?url=jbHRJx477WlWPGA52RhiY3yo2HTjE087QFDNrV7E9dyhES7ftDZ3SdcJZFL4dv4UuXDelpdgdqysjE5y02aICa
+ (void)treeLastInformationWithNode:(BinaryTreeNode *)rootNode resultBlock:(void (^)(NSInteger value))block;
@end
