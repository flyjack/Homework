/*************************************
*** container_of宏的使用
第一部分：const typeof( ((type *)0)->member ) *__mptr = (ptr);
通过typeof定义一个member指针类型的指针变量__mptr，（即__mptr是指向member类型的指针），并将__mptr赋值为ptr。
第二部分： (type *)( (char *)__mptr - offsetof(type,member) )，通过offsetof宏计算出member在type中的偏移，然后用member的实际地址__mptr减去偏移，得到type的起始地址，即指向type类型的指针。
*************************************/

#include <stdio.h>

#define container_of(ptr, type, member) ({          \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define MAX_NAME_LEN 100

struct Test
{
    int id;
    char name[MAX_NAME_LEN];
    int age;
};

typedef struct Test Test;
typedef struct Test * Test_t;

int main()
{
    Test t = {10, "jarrodcal", 88};
    Test_t m = container_of(&(t.age), Test, age);

    printf("%d\n", m->id);
    printf("%s\n", m->name);
    printf("%d\n", m->age);

    return 0;
}
