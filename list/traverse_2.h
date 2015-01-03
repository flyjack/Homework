#ifndef TRAVERSE2_H_
#define TRAVERSE2_H_

#include "list.h"

struct Node_v2
{
    char name[20];
    list list_node;
};

typedef struct Node_v2 Node_v2;

Node_v2 *create_node_v2(int i);
void traverse_node_v2(Node_v2 *node);

#endif
