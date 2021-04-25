/**
*   非递归后序遍历
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
    int     a[50];
    int n;
}Stack;

Status BST_postorderR(NodePtr root, void (*visit)(NodePtr))	//后序非递归遍历
{
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->root[0]=NULL;
    s->n=0;
    memset(s->a,0,sizeof(s->a));

    while(root!=NULL||s->n!=0)
    {
        while(root!=NULL)
        {
            s->n++;
            s->root[s->n]=root;
            if(root->right!=NULL)   s->a[s->n]=1;
            root=root->left;
        }
        if(s->a[s->n]==1)
        {
            s->a[s->n]=2;
            root=s->root[s->n];
            root=root->right;
        }
        else
        {
            visit(s->root[s->n]);
            if(s->a[s->n]!=2)
            {
                root=s->root[s->n];
                root=root->right;
                s->n--;
            }else
            {
                s->n--;
            }
        }
    }
    return true;
}

