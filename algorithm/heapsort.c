#include <stdio.h>

#define MAX_HEAP_LEN 100
static int heap[MAX_HEAP_LEN];
static int heap_size = 0;

/**
demo:
   0
 1   2
3 4 5 6 
**/
 
static void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
 
static void shift_up(int i)
{
    if(i == 0)
        return;

    while (i>0)
    {
        if (heap[(i-1)/2] < heap[i])
            swap(&heap[(i-1)/2], &heap[i]);

        i = (i-1)/2;
    }
}

static void shift_down(int i)
{
    if (2*i+1 > heap_size)
        return;
 
    while (2*i+1 < heap_size)
    {
        i = 2*i+1;

        if ((i+1< heap_size) && (heap[i+1] > heap[i]))
            i++;

        //从孩子节点推断父节点，减少额外变量申请，另下标从0开始，见demo
        if (heap[(i-1)/2] < heap[i])
            swap(&heap[(i-1)/2], &heap[i]);
    }
}

static void delete(int i)
{
    int last = heap[heap_size - 1];
    heap_size--;

    if (i == heap_size)
        return;

    //用最后一个数字覆盖第一个取出的值
    heap[i] = last;
    shift_down(i);
}
 
int delete_max()
{
    int ret = heap[0];
    delete(0);

    return ret;
}
 
void insert(int new_data)
{
    if (heap_size >= MAX_HEAP_LEN) 
        return;

    heap_size++;
    heap[heap_size - 1] = new_data;

    shift_up(heap_size - 1);
}

void traversal()
{
    int i = 0;

    for (; i<heap_size; i++)
        printf("%d\n", heap[i]);
}

int main()
{
    int arr[] = {10, 4, 3, 9, 20, 34, 22};
    int len = sizeof(arr) / sizeof(arr[0]);

    int i = 0;

    for (;i<len;i++)
        insert(arr[i]);

    traversal();

    printf("Heap sort is: \n");

    for (i=0;i<len;i++)
    {
        int v = delete_max();
        printf("%d\n", v);
    }

    return 0;
}
