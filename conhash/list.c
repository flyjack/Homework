#include "list.h"

inline void init_list(list *head)
{
    head->prev = head;
    head->next = head;
}

inline int list_empty(const list *head)
{
    return head->next == head;
}

inline unsigned int list_count(list *head)
{
    unsigned int count = 0;
    list *pos;

    list_for_each(pos, head)
        count++;

    return count;
}

static inline void _list_del(list *prev, list *next)
{
    prev->next = next;
    next->prev = prev;
}

inline void list_del(list *entry)
{
    _list_del(entry->prev, entry->next);
    entry->prev = LIST_POISON1;
    entry->next = LIST_POISON2;
}

static inline void _list_add(list *new, list *prev, list *next)
{
    prev->next = new;
    new->prev = prev;
    new->next = next;
    next->prev = new;
}

inline void list_add_head(list *head, list *new)
{
    _list_add(new, head, head->next);
}

inline void list_add_tail(list *head, list *new)
{
    _list_add(new, head->prev, head);
}
