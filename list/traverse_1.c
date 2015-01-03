#include "traverse_1.h"

Node *create_node(int i)
{
    Node *node = (Node *)calloc(1, sizeof(Node));
    node->id = i;
    node->age = i;

    return node;
}

void traverse_node(Node *node)
{
    list *pos = NULL;
    list *head = &node->list_node;
    Node *val = NULL;

    list_for_each(pos, head)
    {
        val = list_entry(pos, Node, list_node);
        printf("val id is %d\n", val->id);
    }
}
