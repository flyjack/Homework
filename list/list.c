#include "list.h"

void init_list_head(list *head)
{
    head->prve = head;
    head->next = head;
}

//添加新节点时，先修改新节点的指向, 这样才不会变化
void list_add_tail(list *new, list *tail)
{
    new->next = tail->next;
    new->prve = tail;
    tail->next = new;
    new->next->prve = new;
}

void list_add_head(list *new, list *head)
{
    new->next = head;
    new->prve = head->prve;
    head->prve->next = new;
    head->prve = new;
}
