/**
*   层序遍历
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

typedef struct Queue{
    NodePtr root;
    NodePtr next;
}Queue;

Status BST_levelOrder(NodePtr root, void (*visit)(NodePtr))	//层序遍历
{
    Queue *h=(Queue *)malloc(sizeof(Queue));
    Queue *tail=h, *p, *q;
    NodePtr r2;
    int n=0,i,j;
    h->root=root;
    h->next=NULL;
    n++;

    while(n!=0)
    {
        i=n;
        p=h;

        for(j=0;j<i;j++)
        {
            r2=p->root;
            if(r2->left!=NULL)
            {
                q=(Queue *)malloc(sizeof(Queue));
                q->root=r2->left;
                q->next=NULL;
                tail->next=q;
                tail=q;
                n++;
            }
            if(r2->right!=NULL)
            {
                q=(Queue *)malloc(sizeof(Queue));
                q->root=r2->right;
                q->next=NULL;
                tail->next=q;
                tail=q;
                n++;
            }
            p=p->next;
        }
        for(j=0;j<i;j++)
        {
            p=h->root;
            visit(p);
            h=h->next;
            //free(p);
            n--;
        }
    }
    free(h);
    return true;
}

