/******************************************************************
    ***借鉴linux内核中链表的实现方式，核心是通过下面的2个宏，定位到使用链表的数据结构体的地址。 应用此方法实现的链表，有很好的扩展性，和真正的数据类型无关。
    ***服务中，像资源的连接保持，域名检查，具体业务，都有链表的应用场景，其和哈希表都是一种常用且基础的数据结构
*******************************************************************/
#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

struct list
{
    struct list *prve, *next;
};

typedef struct list list;

void  init_list_head(list *head);
void  list_add_tail(list *new, list *tail);
void  list_add_head(list *new, list *head);

#endif
