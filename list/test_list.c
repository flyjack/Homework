#include "traverse_1.h"
#include "traverse_2.h"

int main()
{
    Node *node0 = create_node(0);
    init_list_head(&node0->list_node);

    Node *node1 = create_node(1);
    list_add_tail(&node1->list_node, &node0->list_node);
    Node *node2 = create_node(2);
    list_add_tail(&node2->list_node, &node1->list_node);
    Node *node3 = create_node(3);
    list_add_tail(&node3->list_node, &node2->list_node);

    traverse_node(node0);

    //测试
    Node_v2 *node_v2_0 = create_node_v2(0);
    init_list_head(&node_v2_0->list_node);

    Node_v2 *node_v2_1 = create_node_v2(1);
    list_add_head(&node_v2_1->list_node, &node_v2_0->list_node);
    Node_v2 *node_v2_2 = create_node_v2(2);
    list_add_head(&node_v2_2->list_node, &node_v2_1->list_node);
    Node_v2 *node_v2_3 = create_node_v2(3);
    list_add_head(&node_v2_3->list_node, &node_v2_2->list_node);

    traverse_node_v2(node_v2_0);

    return 0;
}
