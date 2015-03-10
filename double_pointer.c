//二级指针在很多地方都有使用： 1。二维数组申请 2. 链表插入 3. 堆空间在子函数中申请

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMem(char **pp)
{
    *pp = (char *)malloc(sizeof(char) * 10);
}

int main()
{
    char *p = NULL;
    char stu[] = "beijing";
    getMem(&p);
    strcpy(p, stu);
    printf("%s\n", p);
    free(p);

    return 0;
}
