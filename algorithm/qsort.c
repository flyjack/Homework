#include <iostream>
#include <algorithm>

using namespace std;

int partition(int a[], int b, int e)
{
    int pivot = a[e];
    int i;
    //此处的情况
    int k = b;

    for (i=b; i<e; i++)
    {
        if (a[i] <= pivot)
            swap(a[i], a[k++]);
    }

    swap(a[k], a[e]);

    return k;
}

//强调begin<end的，递归必须有跳出的条件
void quick_sort(int a[], int begin, int end)
{
    if (begin < end)
    {
        int pivot = partition(a, begin, end);
        quick_sort(a, begin, pivot-1);
        quick_sort(a, pivot+1, end);
    }
}

int main()
{
    int arr[] = {2, 5, 10, 4, 9, 3, 20, 1, 3, -2, 0, 18};
    int m = 0;
    size_t len = sizeof(arr) / sizeof(arr[0]);

    for (; m<len; m++)
        cout<<arr[m]<<"\t";

    cout<<endl;
    quick_sort(arr, 0, len-1);

    m = 0;

    for (; m<len; m++)
        cout<<arr[m]<<"\t";

    return 0;
}
