#include "traverse_2.h"

Node_v2 *create_node_v2(int i)
{
    Node_v2 *node_v2 = (Node_v2 *)calloc(1, sizeof(Node_v2));
    snprintf(node_v2->name, 20, "%s%d", "jarrodcal_", i);
    return node_v2;
}

void traverse_node_v2(Node_v2 *node)
{
    list *pos = NULL;
    list *head = &node->list_node;
    Node_v2 *val = NULL;

    list_for_each(pos, head)
    {
        val = list_entry(pos, Node_v2, list_node);
        printf("val name is %s\n", val->name);
    }
}
