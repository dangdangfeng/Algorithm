
#import <Foundation/Foundation.h>

@interface ListNode : NSObject

/**
 *  添加节点
 *
 *  @param p   节点指针
 *  @param value 节点值
 *
 *  @return 头结点, 其中头结点 value 为 0
 */
+ (ListNode *)addNode:(ListNode *)p andValue:(id)value;

/**
 *  遍历单链表
 *
 *  @param head 头结点
 *  @param block 处理block
 */
+ (void)traveraslList:(ListNode *)head resultBlock:(void(^)(NSInteger i))block;

/**
 *  单链表逆置
 *
 *  @param head 头结点
 */
+ (void)reverseList:(ListNode *)head;

/// 全链表反转
+ (ListNode *)reverse:(ListNode *)node;
@end
