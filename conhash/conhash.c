/*****************
****由于是链表，查找复杂度平均为O(N), 当节点较多时，TODO需采用二叉查找树，将复杂度控制在O(lgN)
**************/
#include "conhash.h"

//read from config file
char *g_address[4] = {
    "172.16.38.26",
    "172.16.38.26",
    "172.16.38.26",
    "172.16.38.26"
};

char *g_port[4] = {
    "7005",
    "7006",
    "7007",
    "7008"
};

hash_node* g_head = NULL;

#define DUMMY_NODE_SIZE 8

unsigned int hash(const char *s)
{
    register unsigned int hash = 5381;
    const char *m = s;

    while (*m)
    {
        hash += (hash << 5) + (*m++);
    }

    return (hash & 0x7FFFFFFF);
}

static void _add_hash_node(hash_node *head, hash_node *node)
{
    hash_node *hnode = NULL;
    hash_node *bigger = head;

    list_for_each_entry(hnode, &(head->list), list)
    {
        if (hnode->hash_val > node->hash_val)
        {
            bigger = hnode;
            break;
        }
    }

    list_add_tail(&(bigger->list), &(node->list));
}

void create_hash_node()
{
    hash_node* head_node = (hash_node *)calloc(1, sizeof(hash_node));

    if (head_node == NULL)
    {
        printf("calloc hash_node error\n");
        return;
    }

    init_list(&(head_node->list));

    int i = 0;
    int j = 0;

    for (;i<4;i++)
    {
        for (j=0;j<DUMMY_NODE_SIZE;j++)
        {
            hash_node* node = (hash_node *)calloc(1, sizeof(hash_node));
            memcpy(node->ip, g_address[i], strlen(g_address[i]));
            memcpy(node->port, g_port[i], strlen(g_port[i]));
            node->dummy_node_index = j;

            char dummy[3] = {'\0'};
            snprintf(dummy, 3, "%d", j);

            unsigned int port_len = strlen(g_port[i]);
            unsigned int add_len = strlen(g_address[i]);

            char hash_str[32] = {'\0'};
            memcpy(hash_str, g_port[i], port_len);
            memcpy(hash_str+port_len, dummy, 1);
            memcpy(hash_str+port_len+1, g_address[i], add_len);
            
            node->hash_val = hash(hash_str);
            _add_hash_node(head_node, node);
        }
    }

    g_head = head_node;
}

void destory_hash_node()
{
    if (g_head == NULL) return;

    if (list_empty(&(g_head->list)))
        return;
    
    hash_node *iter, *hnode;

    list_for_each_entry_safe(hnode, iter, &(g_head->list), list)
    {
        list_del(&(hnode->list));
        SAFE_FREE(hnode);
    }
}

static hash_node * find_node(unsigned int val)
{
    hash_node *hnode = NULL;
    hash_node *pos = g_head;

    list_for_each_entry(hnode, &(g_head->list), list)
    {
        if (hnode->hash_val > val)
            return hnode;
    }

    //没有找到返回第一个节点
    return list_entry(pos->list.next, hash_node, list);
}

int main()
{
    create_hash_node();

    hash_node *hnode = NULL;
    list_for_each_entry(hnode, &(g_head->list), list)
    {
        printf("%s, %u, %u\n", hnode->port, hnode->hash_val, hnode->dummy_node_index);
    }

    const char *key = "15811225678";
    unsigned int hashval = hash(key);
    hnode = find_node(hashval);
    printf("%s, %s, %u\n", hnode->ip, hnode->port, hnode->dummy_node_index);

    char cmd[100] = {'\0'};
    snprintf(cmd, 100, "echo set %s %d | /usr/local/bin/redis-cli -h %s -p %s", key, 1, hnode->ip, hnode->port);
    system(cmd);

    snprintf(cmd, 100, "echo get %s | /usr/local/bin/redis-cli -h %s -p %s", key, hnode->ip, hnode->port);
    system(cmd);
    
    /*
    unsigned int count = list_count(&(g_head->list));
    printf("count is %u\n", count);

    destory_hash_node();

    count = list_count(&(g_head->list));
    printf("count is %u\n", count);
    */

    return 0;
}
