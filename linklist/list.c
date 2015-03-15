#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *listCreate(void)
{
    list *list;

    if ((list = malloc(sizeof(*list))) == NULL)
        return NULL;

    list->head = list->tail = NULL;
    list->len = 0;
    list->free = NULL;
    list->match = NULL;

    return list;
}

list *listAddNodeTail(list *list, void *value)
{
    listNode *node;

    if ((node = malloc(sizeof(*node))) == NULL)
        return NULL;

    node->value = value;

    if (list->len == 0)
    {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }
    else
    {
        node->prev = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }

    list->len++;

    return list;
}

list *listAddNodeHead(list *list, void *value)
{
    listNode *node;

    if ((node = malloc(sizeof(*node))) == NULL)
        return NULL;

    node->value = value;

    if (list->len == 0)
    {
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }
    else
    {
        node->next = list->head;
        node->prev = NULL;
        list->head->prev = node;
        list->head = node;
    }

    list->len++;

    return list;
}

//if 都要执行
void listDelNode(list *list, listNode *node)
{
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;

    if (list->free)
        list->free(node->value);

    free(node);

    list->len--;
}
