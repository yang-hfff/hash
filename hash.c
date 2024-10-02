#include "hash.h"


//@config
#define HASH_MALLOC malloc
#define HASH_FREE free
#include <stdlib.h>


//哈希组建数据结构
void hash_init(Hash *obj,int size)
{
    obj->size = size;
    obj->table = (Hash_node *)HASH_MALLOC(size*sizeof(void *));
    for(int i = 0;i < size;i++)
    {
        obj->table[i] = HASH_NULL;
    }
}

//哈希插入键值对
void hash_insert(Hash *obj,int key,int value)
{
    int hash_value = key % obj->size;
    Hash_node *d = (Hash_node *)HASH_MALLOC(sizeof(Hash_node));
    
    d->key = key;
    d->value = value;
    d->next = HASH_NULL;

    if(obj->table[hash_value] == HASH_NULL)
    {
        obj->table[hash_value] = d;
    }
    else 
    {
        Hash_node *p = obj->table[hash_value];
        while (p->next != HASH_NULL)
        {
            p = p->next;
        }
        p->next = d;
    }
}

//哈希查找
int hash_search(Hash *obj,int key)
{
    int hash_value = key % obj->size;
    Hash_node *p = obj->table[hash_value];

    while (p != HASH_NULL)
    {
        if(p->key == key)
        {
            return p->value;
        }
        p = p->next;
    }

    return -1;
}


//哈希删除
void hash_delete(Hash *obj,int key)
{
    int hash_value = key % obj->size;
    Hash_node *p,*q;

    if(obj->table[hash_value] != HASH_NULL && obj->table[hash_value]->key == key)
    {
        p = obj->table[hash_value]->next;
        HASH_FREE(obj->table[hash_value]);
        obj->table[hash_value] = p;
    }
    else 
    {
        p = obj->table[hash_value]->next;
        q = obj->table[hash_value];
        while (p != HASH_NULL)
        {
            if(p->key == key)
            {
                q->next = p->next;
                free(p);
                goto escloop;
            }
            p = p->next;   
            q = q->next;         
        }
        //not exist this key
    }
    escloop:;
}


//哈希释放数据结构
void hash_deinit(Hash *obj)
{
    Hash_node *p,*q;

    for(int i = 0;i < obj->size;i++)
    {
        if(obj->table[0] == HASH_NULL)
        {
            continue;
        }
        else 
        {
            p = obj->table[i]->next;
            q = obj->table[i];
            while(p != HASH_NULL)
            {
                HASH_FREE(q);
                q = p;
                p = p->next;
            }
            HASH_FREE(q);
        }
    }
}



