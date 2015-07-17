
//将数组反序列化为二叉树，data为BFS结果
LinkBitree CreatBitree(int data[], int len)
{
    LinkBitree phead = NULL;

    if ((len == 0) || (data[0] == -1)) return phead;

    LinkBitree ptree = NULL;
    queue<LinkBitree> queue;

    phead = (LinkBitree)malloc(sizeof(BitreeNode));
    phead->data = data[0];
    ptree = phead;
    queue.push(ptree);
    int i, j;

    for (i=0; i<len; i++)
    {
        if (data[i] != -1)
        {
            ptree = queue.front();
            queue.pop();

            j = 2 * i + 1;

            if ((j < len) && (data[j] != -1))
            {
                ptree->Lchild = (LinkBitree)malloc(sizeof(BitreeNode));
                ptree->Lchild->data = data[j];
                queue.push(ptree->Lchild);
            }
            else
            {
                ptree->Lchild = NULL;
            }

            j += 1;

            if ((j < len) && (data[j] != -1))
            {
                ptree->Rchild = (LinkBitree)malloc(sizeof(BitreeNode));
                ptree->Rchild->data = data[j];
                queue.push(ptree->Rchild);
            }
            else
            {
                ptree->Rchild = NULL;
            }
        }
    }

    return phead;
}
