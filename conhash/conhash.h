#ifndef __CONHASH__H__
#define __CONHASH__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef unsigned int uint32;

struct hash_node
{
    char ip[16];
    char port[8];
    uint32 dummy_node_index;
    uint32 hash_val;
    struct list list;
};

typedef struct hash_node hash_node;

unsigned int hash(const char *s);
void create_hash_node();
void destory_hash_node();

#define SAFE_FREE(x)    {if (x) {free(x);x = NULL;}}

#endif
