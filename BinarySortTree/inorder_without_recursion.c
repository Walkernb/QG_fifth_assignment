/**
*   非递归中序遍历
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

typedef struct Stack{
    NodePtr root[50];
    int n;
}Stack;

Status BST_inorderR(NodePtr root, void (*visit)(NodePtr))	//中序非递归遍历
{
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->n=0;
    s->root[s->n]=NULL;

    while(s->n!=0||root!=NULL)
    {
        while(root!=NULL)
        {
            s->n++;
            s->root[s->n]=root;
            root=root->left;
        }
        visit(s->root[s->n]);
        root=s->root[s->n];
        root=root->right;
        s->n--;
    }
}
