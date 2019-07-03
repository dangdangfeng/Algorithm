#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
    int item;
    struct  node_s *next;
}node_t;

node_t *reverse_list(node_t *head){
    node_t *n = head;
    head = NULL;
    while (n)
    {
        node_t * m = n;
        n = n -> next;
        m -> next = head;
        head = m;
    }
    return head;
}

node_t *list_create(const int n){
    int i;
    node_t *head;
    node_t *p;
    head = NULL;
    for ( i = 0; i < n; i++)
    {
        p = (node_t *)malloc(sizeof(node_t));
        if (NULL == p)
        {
            perror("Error");
        }
        scanf("%d",&p->item);
        p->next = head;
        head = p;
    }
    return p;
    
}

int main(int argc, char const *argv[])
{
    node_t *list = list_create(10);
    while (list != NULL)
    {
        printf("%d ", list->item);
        list = list->next;
    }
    printf("\n");
    printf("反转 \n");

    node_t *reverseList = reverse_list(list);
    while (reverseList != NULL)
    {
        printf("%d ", reverseList->item);
        reverseList = reverseList->next;
    }
    printf("\n");

    return 0;
}
