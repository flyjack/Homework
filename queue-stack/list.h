#ifndef __LIST_H__
#define __LIST_H__

typedef struct listNode
{
    struct listNode *prev;
    struct listNode *next;
    void *value;
}listNode;

typedef struct list
{
    listNode *head;
    listNode *tail;
    void (*free)(void *ptr);
    int (*match)(void *ptr, void *key);
    unsigned long len;
}list;

#define listLength(l) ((l)->len)
#define listFirst(l) ((l)->head)
#define listLast(l) ((l)->tail)
#define listPrevNode(n) ((n)->prev)
#define listNextNode(n) ((n)->next)
#define listNodeValue(n) ((n)->value)

list *listCreate(void);
void listRelease(list *list);
list *listAddNodeHead(list *list, void *value);
list *listAddNodeTail(list *list, void *value);
void listDelNode(list *list, listNode *node);

#endif
