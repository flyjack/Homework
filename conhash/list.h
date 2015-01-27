#ifndef __LIST__H__
#define __LIST__H__

#define prefetch(x) __builtin_prefetch(x)

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({                   \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})

struct list
{
    struct list *prev, *next;
};

typedef struct list list;

//访问此指针时会出错，便于查找问题不设置为NULL
#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

#define list_for_each(pos, head) \
    for (pos = (head)->next; prefetch(pos->next), pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) container_of(ptr, type, member)

//不涉及到删除节点时使用此宏
#define list_for_each_entry(pos, head, member)                      \
    for (pos = list_entry((head)->next, typeof(*pos), member);      \
        &pos->member != (head);                                     \
        pos = list_entry(pos->member.next, typeof(*pos), member))

//遍历过程中涉及到删除节点时，使用此宏
#define list_for_each_entry_safe(pos, n, head, member)              \
    for (pos = list_entry((head)->next, typeof(*pos), member),      \
        n = list_entry(pos->member.next, typeof(*pos), member);     \
        &pos->member != (head);                                     \
        pos = n, n = list_entry(n->member.next, typeof(*n), member))

inline void init_list(list *head);
inline int  list_empty(const list *head);
inline unsigned int list_count(list *head);

inline void list_del(list *entry);
inline void list_add_head(list *head, list *new);
inline void list_add_tail(list *head, list *new);
#endif
