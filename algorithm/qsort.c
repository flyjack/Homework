#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int len, int index)
{
    int temp = arr[index];
    int s_len = 0;
    int i = 0;

    swap(&arr[index], &arr[len-1]);

    for (; i<len; i++)
    {
        if (arr[i]<temp)
        {
            swap(&arr[i], &arr[s_len]);
            s_len++;
        }
    }

    swap(&arr[len-1], &arr[s_len]);

    return s_len;
}

void quick_sort(int *arr, int len)
{
    if (len == 0 || len == 1)
        return;

    int small_len = partition(arr, len, 0);

    quick_sort(arr, small_len);
    
    //将标杆值也进行了调换，所以下标开始要加1, 且注意&
    quick_sort(&arr[small_len+1], len-small_len-1);
}

int main()
{
    int arr[] = {2, 5, 10, 4, 9, 3, 20, 1, 3, -2, 0, 18};
    int m = 0;
    size_t len = sizeof(arr) / sizeof(arr[0]);

    for (; m<len; m++)
        printf("%d\t", arr[m]);

    printf("\n");
    quick_sort(arr, len);

    m = 0;

    for (; m<len; m++)
        printf("%d\t", arr[m]);

    return 0;
}
