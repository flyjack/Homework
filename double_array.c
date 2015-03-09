//申请二维数组的方法，差别在于申请的空间是否连续, 另外巧妙利用数组a【】同时也为地址的写法
//参考http://03071344.lofter.com/post/10871e_34cade

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** getMemB(int m, int n)
{
    int **p = (int **)malloc(sizeof(int*) * m);
    p[0] = (int *)malloc(sizeof(int) * m * n);
    
    //if (p)
    
    memset(p[0], 0, m*n);

    int i = 1;
    int j = 0;

    for (;i<m;i++)
        p[i] = p[i-1] + n;

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            p[i][j] = i*n+j;
            printf("%d ", p[i][j]);
        }

        printf("\n");
    }

    return p;
}


int ** getMemA(int m, int n)
{
    int **p = (int **)malloc(sizeof(int *) * m);
    
    //if (p)

    int i = 0;
    int j = 0;

    for (;i<m;i++)
    {
        p[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            p[i][j] = i*n+j;
            printf("%d ", p[i][j]);
        }

        printf("\n");
    }

    return p;
}

int main()
{
    /*
    int ** arr = getMemA(3, 4);
    
    int m = 3;
    int n = 4;
    int i,j;

    printf("main func print\n");

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", arr[i][j]);
        }

        free(arr[i]);
        arr[i] = NULL;

        printf("\n");
    }

    free(arr);
    */

    int ** arr = getMemB(3, 4);
    
    int m = 3;
    int n = 4;
    int i,j;

    printf("main func print\n");

    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    free(arr[0]);
    arr[0] = NULL;

    free(arr);
    
    return 0;
}
