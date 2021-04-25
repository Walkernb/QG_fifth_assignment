/**
*   查找节点
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

Status BST_search(NodePtr root, ElemType e)
{
    int i=true;
    if(root==NULL)   return false;                  //没有该节点
    if(root->value<e)   i=BST_search(root->right,e);
    else  if(root->value>e)      i=BST_search(root->left,e);
    return i;                                    //有该节点
}

void SearchNode(NodePtr root)
{
    ElemType e;
    printf("请输入要查询的节点：");
    scanf("%d",&e);
    int i=BST_search(root,e);
    if(i==true) printf("树中有该节点！\n");
    else        printf("树中没有该节点！\n");
}

