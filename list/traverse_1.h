#ifndef TRAVERSE1_H_
#define TRAVERSE1_H_

#include "list.h"

struct Node
{
    int id;
    int age;
    list list_node;
};

typedef struct Node Node;

Node *create_node(int i);
void traverse_node(Node *node);

#endif
