#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct stu
{
    char name[12];
    unsigned int sex:4;
    unsigned char height;
};

typedef struct stu stu;

stu **getStudents(int count)
{
    stu **ppStu = (stu **)malloc(sizeof(stu *) * count);

    int i = 0;

    for (;i<count;i++)
    {
        ppStu[i] = (stu *)malloc(sizeof(stu));
        ppStu[i]->height = i+1;
    }

    return ppStu;
}

int main()
{
    int i = 0;
    int count = 20;
    stu **ppStu = getStudents(count);

    list *list = listCreate();
    
    for (;i<20;i++)
    {
        listAddNodeTail(list, ppStu[i]);
    }

    printf("len is %d\n", listLength(list));

    //通过访问头或者尾来实现队列或者栈
    for (i=0;i<20;i++)
    {
        listNode *node = listLast(list);
        //listNode *node = listFirst(list);
        stu *p = (stu *)(listNodeValue(node));
        printf("height is %u\n", p->height);
        
        listDelNode(list, node);
    }

    return 0;
}
