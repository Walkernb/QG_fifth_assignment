/**
*   ���ҽڵ�
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
    if(root==NULL)   return false;                  //û�иýڵ�
    if(root->value<e)   i=BST_search(root->right,e);
    else  if(root->value>e)      i=BST_search(root->left,e);
    return i;                                    //�иýڵ�
}

void SearchNode(NodePtr root)
{
    ElemType e;
    printf("������Ҫ��ѯ�Ľڵ㣺");
    scanf("%d",&e);
    int i=BST_search(root,e);
    if(i==true) printf("�����иýڵ㣡\n");
    else        printf("����û�иýڵ㣡\n");
}

