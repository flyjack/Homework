#include <stdio.h>

//自己实现入栈和出栈的情况， 不要用递归的思想，递归开销不小
int search(int a[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid -1;
        else
            low = mid + 1;
    }

    return -1;
}

//递归思想，递归思路不要忘记函数中return的地方
int _search(int a[], int low, int high, int key)
{
    if (high < low)
        return -1;

    int mid = low + (high - low) / 2;

    if (a[mid] == key)
    {
        printf("Find key index is %d\n", mid);
        return mid;
    }

    if (a[mid] > key)
        return _search(a, low, mid-1, key);

    if (a[mid] < key)
        return _search(a, mid+1, high, key);
}

int main()
{
    int arr[] = {10, 33, 49, 80, 220, 1000};
    int len = sizeof(arr) / sizeof(int);

    int m = search(arr, 0, len-1, 80);
    printf("m is %d\n", m);

    return 0;
}
