/***********************************************************
****  类似查询某个单词是否在一个集合中且集合中的单词有规律，有公共前缀，如：敏感词查询，统计单词出现次数和位置，单词去重，Top N问题, 前缀子串
****  没有具体压测过，网上说性能整体比hash和red-black tree好
****  是典型的拿空间换时间的数据结构, 查询复杂度为树的高度，o(H)
****  TODO 可以采用双数组（Double-Array）实现。利用双数组可以大大减小内存使用量http://baike.baidu.com/view/11508220.htm?fr=aladdin
****  hash无决近似串的查找
*********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define末尾不加；
#define MAX_NUM 58

//节点的状态标示
enum NODE_TYPE
{
    COMPLETED,
    UNCOMPLETED
};

struct Node
{
    enum NODE_TYPE node_type;
    char ch;
    int times;
    struct Node *next[MAX_NUM];
};

typedef struct Node Node;
Node * ROOT = NULL;
int g_heapSize = 0;

static Node *create_node(char ch)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        printf("init_tire malloc error \n");
        return;
    }

    node->node_type = UNCOMPLETED;
    node->ch = ch;
    node->times = 1;

    int i = 0;

    for (; i<MAX_NUM; i++)
        node->next[i] = NULL;

    return node;
}

void init_tire()
{
    ROOT = create_node(' ');
}

static int char_2_index(char ch)
{
    return ch - 'A';
}

void insert(const char str[], int len)
{
    int i = 0;
    Node *ptr = ROOT;
    int depth = 0;

    while (i < len)
    {
        if (isalpha(str[i]))
        {
            depth++;

            int index = char_2_index(str[i]);

            if (ptr->next[index] == NULL)
                ptr->next[index] = create_node(str[i]);

            ptr = ptr->next[index];
        }

        i++;
    }

    if (depth > g_heapSize)
        g_heapSize = depth;
}

void free_tire(Node *node)
{
    int i = 0;

    for (; i<MAX_NUM; i++)
    {
        if (node->next[i] != NULL)
        {
            free(node->next[i]);
            node->next[i] = NULL;
        }
    }

    free(node);
    node = NULL;
}

void traverse(Node *node)
{
    int i = 0;
    int j = 0;
    Node *pnode = node;
    char s[14] = {0};

    for (; j<14; j++)
    {
        for (; i<MAX_NUM; i++)
        {
            pnode = pnode->next[i];

            if (!pnode)
                printf("%c", pnode->ch);
        }

        printf("\n");
    }
}

int main()
{
    init_tire();

    char str[] = "This week, the streets of New York City and the timelines of Twitter will intersect with fashion-forward looks from New York Fashion Week (#NYFW). The bedecked and bejeweled will take conversations around their favorite shows and looks to Twitter, where they’ll share their experiences in 140 characters, enhanced by photos and video.";
    const char *s = " ";
    char *pch =  strtok(str, s);

    while (pch != NULL)
    {
        int len = strlen(pch);

        insert(pch, len);
        pch = strtok(NULL, s);
    }
    
    traverse(ROOT);

    return 0;
}
