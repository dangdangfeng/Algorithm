
#import "ListNode.h"

// 单向链表
@interface ListNode (){
    id val;
    ListNode *next;
}

@end

@implementation ListNode

+ (ListNode *)addNode:(ListNode *)p andValue:(id)value{
    if (p == nil) {
        p = [[ListNode alloc] init];
        p->val = value;
        p->next = nil;
    }else{
        p->next = [ListNode addNode:p->next andValue:value];
    }
    return p;
}

+ (void)traveraslList:(ListNode *)head resultBlock:(void(^)(NSInteger i))block{
    if(head->next == nil){
        if (block) {
            block([head->val integerValue]);
        }
        return;
    }
    if (block) {
        block([head->val integerValue]);
    }
    [ListNode traveraslList:head->next resultBlock:block];
}

+ (void)reverseList:(ListNode *)head{
    ListNode *p = head;
    ListNode *s = p->next;
    
    while (s->next != nil) {
        ListNode *t = s->next;
        s->next = p;
        p = s;
        s = t;
    }
    
    s->next = p;
    head->next->next = nil; //尾指针置为空
    head->next = s; //赋值到头指针后一位
}

+ (ListNode *)reverse:(ListNode *)node{
    ListNode *current,*pnext,*prev;
    
    if (!node) return nil;
    if (!node->next) return node;
    
    current = node;
    pnext = current->next;
    current->next = nil;
   
    while (pnext) {
        prev = pnext->next;
        pnext->next = current;
        current = pnext;
        pnext = prev;
    }
    node = current;
    
    
    
    return node;
   
    
}

@end
