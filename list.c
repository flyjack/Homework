//二维指针在单链表中应用较为广泛，可以将灵活多变的头节点进行改变, 双向链表使用较少，因为有单独的头尾节点

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

void listPopHead(Node **linkp)
{
    Node *entry = *linkp;
    *linkp = (*linkp)->next;
    printf("pop head value is %d\n", entry->value);
    free(entry);
}

void listAddHead(Node **linkp, int value)
{
    Node *new = (Node *)malloc(sizeof(Node));

    if (new == NULL)
        return;

    new->value = value;
    new->next = (*linkp==NULL)? NULL: *linkp;

    *linkp = new;
}

void _insertLinkList(Node **linkp, int value)
{
    register Node *cur;
    register Node *new;

    while (((cur = *linkp) != NULL) && (cur->value < value))
        linkp = &cur->next;

    new = (Node *)malloc(sizeof(Node));

    if (new == NULL)
        return;

    new->value = value;
    new->next = cur;

    *linkp = new;
}

//针对有可能在链表的头部插入节点, 修改根指针，使用二级指针指向根节点
//善于使用指针，指向后面节点的地址域，不用在遍历时申请一个prev, 记录当前的节点前一个节点是否是头结点
void insertLinkList(Node **p, int value)
{
    Node *pre = NULL;
    Node *cur = *p;

    while (cur != NULL && cur->value < value)
    {
        pre = cur;
        cur = cur->next;
    }

    Node *new = (Node *)malloc(sizeof(Node));

    if (new == NULL)
        return;

    new->value = value;
    new->next = cur;

    if (pre == NULL)
        *p = new;
    else
        pre->next = new;

    return;
}

void traverseLinkList(Node **p)
{
    Node *cur = *p;

    while (cur)
    {
        printf("value is %d\t", cur->value);
        cur = cur->next;
    }
}

void _deleteNode(Node **p, int value)
{
    register Node **cur = p;
    register Node *entry;

    while (*cur)
    {
        entry = *cur;

        if (entry->value == value)
        {
            *cur = entry->next;

            free(entry);
            entry = NULL;
            break;
        }

        cur = &entry->next;
    }
}

//反转单链表，思路主要是添加一个伪节点，进行逆序
void rotateLinklist(Node **linkp)
{
    Node *cur = *linkp;
    Node *last = NULL;
    Node *next;

    while (cur)
    {
        next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }

    *linkp = last;
}

void deleteNode(Node **p, int value)
{
    register Node *cur = *p;
    register Node *prev = NULL;

    while (cur)
    {
        if (cur->value == value)
        {
            if (prev == NULL)
                *p = cur->next;
            else
                prev->next = cur->next;

            free(cur);
            cur = NULL;
            break;
        }

        prev = cur;
        cur = cur->next;
    }
}

//TODO reverse list
void reverseLinkList(Node **p)
{

}

void freeLinkList(Node **p)
{
    Node *cur = *p;
    Node *temp;

    while (cur)
    {
        temp = cur;
        cur = cur->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    int i = 0;
    srand(time(NULL));

    for (;i<10;i++)
    {
        int v = rand() / 10000;
        _insertLinkList(&head, v);
    }

    _insertLinkList(&head, 30000);
    traverseLinkList(&head);
    printf("\n");
    rotateLinklist(&head);

    traverseLinkList(&head);
/*
    for (i=0;i<11;i++)
        listPopHead(&head);

    traverseLinkList(&head);

    deleteNode(&head, 30000);
    printf("After delete .... \n");

    traverseLinkList(&head);
    printf("After reverse .... \n");
*/
    freeLinkList(&head);

    return 0;
}
