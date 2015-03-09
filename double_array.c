//申请二维数组的方法，差别在于申请的空间是否连续

#include <stdio.h>
#include <stdlib.h>

int ** getMem(int m, int n)
{
    int **p = (int **)malloc(sizeof(int *) * m);

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
    int ** arr = getMem(3, 4);
    
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
    
    return 0;
}
