#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

//不能在相同的键插入两次（即键不能重复）
//Hash结构体不能是空指针（table成员会自动分配，结构体本体不负责分配）
//BUG[1] 删除节点有时候段错误（只有重复的键存入才可能发生）
//BUG[2] 释放结构体有时候段错误（只有重复的键存入才可能发生）

int main(void)
{
    Hash ha;
    int a,b;

    hash_init(&ha,5);

    printf("请输入%d次键值对(键值对用空格分开，回车完成一对\n",ha.size);
    for(int i = 0;i < ha.size;i++)
    {
        scanf("%d%d",&a,&b);
        hash_insert(&ha,a,b);
    }

    printf("用键删除两个\n");
    scanf("%d",&a);
    hash_delete(&ha,a);
    scanf("%d",&a);
    hash_delete(&ha,a);

    printf("输入键查找你的键值对\n");
    for(int i = 0;i < ha.size;i++)
    {
        scanf("%d",&a);
        printf("(%d,%d)\n",a,hash_search(&ha,a));
    }

    hash_deinit(&ha);

    puts("xxxxx\n");
    return 0;
}