/**
*   插入节点
*/

#include<stdio.h>
#include<stdlib.h>

#define BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root ;
} BinarySortTree, *BinarySortTreePtr;

extern Status BST_search(BinarySortTreePtr bt, ElemType e);
extern Status Cmp(NodePtr root ,ElemType e) ;

NodePtr create_Node(int e)                       //创建节点
{
    NodePtr p=(NodePtr)malloc(sizeof(Node));
    p->value=e;
    p->left=NULL;
    p->right=NULL;
    return p;
}

BinarySortTreePtr BST_insert(BinarySortTreePtr bt)              //插入节点
{
    ElemType e;
    printf("请输入要插入的数字：");
    scanf("%d",&e);

    NodePtr root=bt->root;
    if(BST_search(bt->root,e))                              //树中已有该数
    {
        printf("树中已有该节点！\n");
        return bt;
    }

    if(bt->root->value==0)
    {
        bt->root->value=e;
        return bt;
    }

    int i=Cmp(bt->root,e);
    while(i)
    {
        if(i==1)                        //往右子树找
        {
            i=Cmp(bt->root->right,e);
            if(i==0)
            {
                bt->root->right=create_Node(e);
                break;
            }
            bt->root=bt->root->right;
        }
        else                            //往左子树找
        {
            i=Cmp(bt->root->left,e);
            if(!i)
            {
                bt->root->left=create_Node(e);
                break;
            }
            bt->root=bt->root->left;
        }
    }

    bt->root=root;
    return bt;
}
