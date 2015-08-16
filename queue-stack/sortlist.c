#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct List
{
    struct ListNode *head;
    struct ListNode *tail;
    int length;
};

typedef struct List List;

List *initList()
{
    List *plist = (List *)calloc(1, sizeof(List));
    plist->head = plist->tail = NULL;
    plist->length = 0;

    return plist;
}

void insertList(List *plist, int val)
{
    ListNode* node = (ListNode *)calloc(1, sizeof(ListNode));
    node->val = val;
    node->next = NULL;

    if (plist->length == 0)
    {
        plist->head = node;
        plist->tail = node;
    }
    else
    {
        plist->tail->next = node;
        plist->tail = node;
    }

    plist->length++;

    return;
}

void freeList(List *plist)
{
    //free node
}


static ListNode * mergeList(ListNode *left, ListNode *right)
{
    if (left == NULL)   return right;
    if (right == NULL)  return left;

    ListNode result = {-1, NULL};
    ListNode *p = &result;

    while (left && right)
    {
        if (p->val == left->val)
        {
            left = left->next;
            continue;
        }

        if (p->val == right->val)
        {
            right = right->next;
            continue;
        }

        if(left->val > right->val)
            p->next = right, p = right, right = right->next;
        else
            p->next = left, p = left, left = left->next;
    }

    if (left) p->next = left;
    if (right) p->next = right;

    return result.next;
}

ListNode * sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
            return head;

    ListNode *fast = head;
    ListNode *slow = head;

    while ((fast->next) && (fast->next->next))
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow;
    slow = slow->next;
    fast->next = NULL;

    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    return mergeList(left, right);
}

int main()
{
    List *plist = initList();
    int i;

    for (i=4; i<100000; i++)
        insertList(plist, i);

    for (i=3000; i<100000; i++)
        insertList(plist, i);

    ListNode *pnode = sortList(plist->head);

    while (pnode)
    {
        printf("%d\t", pnode->val);
        pnode = pnode->next;
    }

    return 0;
}
