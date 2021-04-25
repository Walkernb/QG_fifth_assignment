/**
*   先序非递归排序
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

//extern void visit(NodePtr e);

Status BST_preorderR(NodePtr root, void (*visit)(NodePtr))	    //先序非递归排序
{
    NodePtr r2;
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s->root[0]=NULL;
    s->n=0;

    s->n++;
    s->root[s->n]=root;


    while(s->n!=0)                 //Õ»·Ç¿Õ
    {
        visit(s->root[s->n]);
        r2=s->root[s->n];
        s->n--;

        if(r2->right!=NULL)
        {
            s->n++;
            s->root[s->n]=r2->right;
        }

        if(r2->left!=NULL)
        {
            s->n++;
            s->root[s->n]=r2->left;
        }
    }
    return 1;
}
