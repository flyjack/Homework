#include <stdio.h>
#include <stdlib.h>

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
    LinkBitree data[20];
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
    pstack = (LinkStack)malloc(sizeof(StackNode));

    if (pstack == NULL)
    {
        printf("内存分配失败!");
        exit(0);
    }
    
    pstack->top = 0;
    
    return pstack;
}

void PostorderTraverse(LinkBitree phead, LinkStack pstack1, LinkStack pstack2)
{
    do 
    {
        while (phead)
        {
            if (phead->Lchild)
            {
                pstack1->data[pstack1->top] = phead->data;
                pstack1->top++;
                phead = phead->Lchild;
            }
            else
            {
                if (phead->Rchild)
                {
                    pstack1->data[pstack1->top] = phead->data;
                    pstack1->top++;
                    phead = phead->Rchild;
                }
                else
                {
                    pstack2->data[pstack2->top] = phead->data;
                    pstack2->top++;
                    phead = NULL;
                }
            }
        }

        if (pstack2->top)
        {
            pstack2->top--;
            phead = pstack2->data[pstack2->top];
            printf("%d\t", phead->data);

            pstack1->top--;
            phead = pstack1->data[pstack1->top];
            printf("%d\t", phead->data);
        }

    } while(pstack1->top || phead);
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

    return 0;
}
