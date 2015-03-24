//TODO二叉树的后序遍历存在问题

//gcc -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_COUNT 20

struct Bitree
{
    int data;
    struct Bitree *Lchild,*Rchild;
};

typedef struct Bitree BitreeNode;
typedef struct Bitree * LinkBitree;

//创建一个顺序结构存储的栈
struct Stack
{
    LinkBitree data[MAX_STACK_COUNT];
    int top;
};

typedef struct Stack StackNode;
typedef struct Stack * LinkStack;

LinkBitree CreatBitree();
LinkStack InitStack();
void InorderTraverse(LinkBitree, LinkStack);

LinkBitree CreatBitree()
{
    int data;
    LinkBitree phead;

    scanf("%d", &data);

    if (data == 0)
        return NULL;

    phead = (LinkBitree)malloc(sizeof(BitreeNode));

    if (phead == NULL)
    {
        printf("内存分配失败!");
        exit(0);
    }

    phead->data = data;

    printf("Please Input %d left node \n", phead->data);
    phead->Lchild = CreatBitree();
    printf("Please Input %d right node \n", phead->data);
    phead->Rchild = CreatBitree();

    return phead;
}

LinkStack InitStack()
{
    LinkStack pstack;
    pstack = (LinkStack)calloc(1, sizeof(StackNode)); 

    if (pstack == NULL)
    {
        printf("内存分配失败!");
        exit(0);
    }
    
    return pstack;
}

void PostorderTraverse(LinkBitree phead, LinkStack pstack1, LinkStack pstack2)
{

}

void InorderTraverse(LinkBitree phead, LinkStack pstack)
{
    do 
    {
        while (phead)
        {
            pstack->data[pstack->top] = phead;
            pstack->top++;
            phead = phead->Lchild;
        }

        if (pstack->top)
        {
            pstack->top--;
            phead = pstack->data[pstack->top];
            printf("%d\t", phead->data);
            phead = phead->Rchild;
        }
    } while(phead || pstack->top);
}

void PreorderTraverse(LinkBitree phead, LinkStack pstack)
{
    do
    {
        while (phead)
        {
            printf("%d\t", phead->data);
            pstack->data[pstack->top] = phead;
            pstack->top++;
            phead = phead->Lchild;
        }

        if (pstack->top)
        {
            pstack->top--;
            phead = pstack->data[pstack->top];
            phead = phead->Rchild;
        }

    } while(pstack->top || phead);
}

void _InorderTraverse(LinkBitree phead)
{
    if (phead)
    {
        if (phead->Lchild)
            _InorderTraverse(phead->Lchild);

        printf("%d\t", phead->data);

        if (phead->Rchild)
            _InorderTraverse(phead->Rchild);
    }

    return;
}

void _PreorderTraverse(LinkBitree phead)
{
    if (phead)
    {
        printf("%d\t", phead->data);

        if (phead->Lchild)
            _PreorderTraverse(phead->Lchild);

        if (phead->Rchild)
            _PreorderTraverse(phead->Rchild);
    }

    return;
}

void _PostorderTraverse(LinkBitree phead)
{
    if (phead)
    {
        if (phead->Lchild)
            _PostorderTraverse(phead->Lchild);

        if (phead->Rchild)
            _PostorderTraverse(phead->Rchild);

        printf("%d\t", phead->data);
    }

    return;
}

void leverTraverse(LinkBitree phead, LinkStack pstack)
{
    if (phead == NULL)
        return;

    pstack->data[pstack->top] = phead;
    pstack->top++;

    int cur = 0;

    while (cur < pstack->top)
    {
        int last = pstack->top;

        while (cur < last)
        {
            LinkBitree ptree = pstack->data[cur];
            printf("%d ", ptree->data);

            if (ptree->Lchild)
            {
                pstack->data[pstack->top] = ptree->Lchild;
                pstack->top++;
            }

            if (ptree->Rchild)
            {
                pstack->data[pstack->top] = ptree->Rchild;
                pstack->top++;
            }

            cur++;
        }

        printf("\n");
    }
}

int main()
{
    printf("Please tree node \n");
    LinkBitree phead = CreatBitree();
    LinkStack pstack = InitStack();

    printf("Recursion get tree node:\n");

    _PreorderTraverse(phead);
    printf("\n");
    _InorderTraverse(phead);
    printf("\n");
    _PostorderTraverse(phead);
    printf("\n");
    
    printf("Non Recursion get tree node \n");
    PreorderTraverse(phead, pstack);
    printf("\n");
    InorderTraverse(phead, pstack);
    printf("\n");
    //PostorderTraverse(phead, pstack);

    printf("Lever Traverse is \n");
    leverTraverse(phead, pstack);
    
    return 0;
}
