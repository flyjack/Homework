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
