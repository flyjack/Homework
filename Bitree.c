//TODO二叉树的后序遍历存在问题

//gcc -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STACK_COUNT 20

struct Bitree
{
    int data;
    int index;
    struct Bitree *Lchild,*Rchild;
    int nMaxLeft;
    int nMaxRight;
    struct Bitree *parent;
};

typedef struct Bitree BitreeNode;
typedef struct Bitree * LinkBitree;

int nMaxLen = 0;

//树的问题可以转化为链表的问题
//二叉树的序列化，注意递归，堆栈和队列的使用
//保存二叉树形态，注意应用i 2i 2i+1的关系
struct BitreeIndex
{
    LinkBitree ptree;
    unsigned int index;
};

typedef struct BitreeIndex BitreeIndex;
typedef struct BitreeIndex * LinkBitreeIndex;

//创建一个顺序结构存储的栈
struct Stack
{
    LinkBitree data[MAX_STACK_COUNT];
    int top;
};

typedef struct Stack StackNode;
typedef struct Stack * LinkStack;

//建立树的时候保存下标关系
LinkBitree CreatBitree(int index, LinkBitree parent)
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
    phead->index = index;
    phead->parent = parent;

    printf("Please Input %d left node \n", phead->data);
    phead->Lchild = CreatBitree(index*2, phead);
    printf("Please Input %d right node \n", phead->data);
    phead->Rchild = CreatBitree(index*2+1, phead);

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

//销毁一个树，左右子树都没有的情况下进行销毁
void freeBitree(LinkBitree phead)
{
    if (phead)
    {
        if ((phead->Lchild == NULL) && (phead->Rchild == NULL))
            free(phead);

        if (phead->Lchild)
            freeBitree(phead->Lchild);

        if (phead->Rchild)
            freeBitree(phead->Rchild);
    }

    return;
}

//height的高度也为树的高度, max为二叉树的宽度
void leverTraverse(LinkBitree phead, LinkStack pstack)
{
    if (phead == NULL)
        return;

    pstack->data[pstack->top] = phead;
    pstack->top++;

    int height = 0;
    int cur = 0;
    int width = 0;
    int max = 0;

    while (cur < pstack->top)
    {
        int last = pstack->top;

        while (cur < last)
        {
            LinkBitree ptree = pstack->data[cur];
            printf("%d ", ptree->data);
            width++;

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

        height++;
        max = (width > max)? width: max;
        width = 0;
        printf("\n");
    }

    printf("height is %d, width is %d\n", height, max);
}

void traverseBitreeIndex(LinkBitreeIndex pindex)
{

}

void serializeBitree(LinkBitree phead)
{
    if (phead)
    {
        if (phead->parent)
        {
            LinkBitree parent = phead->parent;

            printf("data %d, index %d, nMaxLeft %d, nMaxRight %d, parent %d \n", phead->data, phead->index, phead->nMaxLeft, phead->nMaxRight, parent->data);
        }
        else
        {
            printf("data %d, index %d, nMaxLeft %d, nMaxRight %d \n", phead->data, phead->index, phead->nMaxLeft, phead->nMaxRight);
        }

        if (phead->Lchild)
            serializeBitree(phead->Lchild);

        if (phead->Rchild)
            serializeBitree(phead->Rchild);
    }

    return;
}

//转化为求两条链表的交叉点
LinkBitree findCommonParent(BitreeNode *ch1, BitreeNode *ch2, LinkBitree phead)
{
    if (phead == NULL)
        return NULL;

    if (ch1 == NULL || ch2 == NULL)
        return NULL;

    BitreeNode *ptree = ch1;

    while (ch2 != phead)
    {
        while (ptree != phead)
        {
            if (ptree == ch2)
                return ptree;

            ptree = ptree->parent;
        }

        ch2 = ch2->parent;
        ptree = ch1;
    }

    return phead;
}

//一个节点的左支点的值是其下面孩子节点值的和且是最大值
//最大值是全局的变量
void FindMaxLen(LinkBitree pRoot)
{
    if (pRoot == NULL)
        return;

    if (pRoot -> Lchild == NULL)
        pRoot -> nMaxLeft = 0;

    if (pRoot -> Rchild == NULL)
        pRoot -> nMaxRight = 0;

    if (pRoot -> Lchild != NULL)
        FindMaxLen(pRoot -> Lchild);

    if (pRoot -> Rchild != NULL)
        FindMaxLen(pRoot -> Rchild);

    if (pRoot -> Lchild != NULL)
    {
        int nTempMax = 0;

        if (pRoot->Lchild->nMaxLeft > pRoot->Lchild->nMaxRight)
            nTempMax = pRoot->Lchild->nMaxLeft;
        else
            nTempMax = pRoot->Lchild->nMaxRight;

        pRoot->nMaxLeft = nTempMax + 1;
    }

    if (pRoot -> Rchild != NULL)
    {
        int nTempMax = 0;

        if (pRoot->Rchild->nMaxLeft > pRoot->Rchild->nMaxRight)
            nTempMax = pRoot->Rchild->nMaxLeft;
        else
            nTempMax = pRoot->Rchild->nMaxRight;

        pRoot->nMaxRight = nTempMax + 1;
    }

    if (pRoot -> nMaxLeft + pRoot -> nMaxRight > nMaxLen)
        nMaxLen = pRoot -> nMaxLeft + pRoot -> nMaxRight;
}

int main()
{
    printf("Please tree node \n");
    LinkBitree phead = CreatBitree(1, NULL);
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

    printf("---------------------\n");
    FindMaxLen(phead);
    printf("Max len is %d\n", nMaxLen);
    serializeBitree(phead);

    printf("---------------------\n");
    BitreeNode *ptree1 = phead->Lchild->Rchild;
    BitreeNode *ptree2 = phead->Rchild->Rchild;
    BitreeNode *tree = findCommonParent(ptree1, ptree2, phead);

    if (tree != NULL)
        printf("value is %d \n", tree->data);

    freeBitree(phead);
    free(pstack);

    return 0;
}
