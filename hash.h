#ifndef __HASH_H
#define __HASH_H

/*空缺节点*/
#define HASH_NULL   ((Hash_node *)0)

/*哈希节点*/
typedef struct hash_node
{
    int key;
    int value;
    struct hash_node *next;
}Hash_node;

/*哈希结构体*/
typedef struct hash
{
    int size;
    struct hash_node **table;
}Hash;

/*公共函数*/
void hash_init(Hash *obj,int size);
void hash_insert(Hash *obj,int key,int value);
int hash_search(Hash *obj,int key);
void hash_delete(Hash *obj,int key);
void hash_deinit(Hash *obj);

#endif /*__HASH_H*/