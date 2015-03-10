//二级指针在很多地方都有使用： 1。二维数组申请 2. 链表插入 3. 堆空间在子函数中申请

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getMem(char **pp)
{
    *pp = (char *)malloc(sizeof(char) * 10);
}

//c语言中的函数参数都是传值调用
//对指针p地址的赋值，是将值赋给了局部变量，应该使用二级指针，类比于swap函数
void wrong_getMem(char *p)
{
    printf("param dest %d\n", &p);
    p = (char *)malloc(sizeof(char) * 10);
}

int main()
{
    char *p = NULL;
    printf("src dest is %u\n", &p);
    char stu[] = "beijing";
    getMem(&p);
    strcpy(p, stu);
    printf("%s\n", p);
    free(p);

    return 0;
}
