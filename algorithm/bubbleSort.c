//冒泡排序, 原理要搞懂
void bubbleSort(ListNode *head)
{
    int len = 0;
    for (ListNode *p = head; p != NULL; p = p->next) len++;

    for (int i = 1; i < len; i++)
    {
        ListNode *p = head;
        for(int j = 0; j < len - i; j++, p = p->next)
            if (p->val > p->next->val)
            {
                int tem = p->val; 
                p->val = p->next->val; 
                p->next->val = tem;
            }
    }
}
