#import <Foundation/Foundation.h>

@interface BinaryTreeNode : NSObject
/**
 *  值
 */
@property (nonatomic, assign) NSInteger value;
/**
 *  左节点
 */
@property (nonatomic, strong) BinaryTreeNode *leftNode;
/**
 *  右节点
 */
@property (nonatomic, strong) BinaryTreeNode *rightNode;

/// 便利构造器
+ (instancetype)nodeWithValue:(NSInteger)value;

@end
