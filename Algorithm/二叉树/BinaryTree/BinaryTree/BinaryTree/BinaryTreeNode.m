#import "BinaryTreeNode.h"

@implementation BinaryTreeNode

+ (instancetype)nodeWithValue:(NSInteger)value
{
    BinaryTreeNode *node = [[super alloc] init];
    node.value = value;
    return node;
}
@end
