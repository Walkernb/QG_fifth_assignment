/**
*   删除节点
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

NodePtr Traverse_max(NodePtr node)
{
    if(node->right==NULL||node->right->right==NULL)   return node;
    return Traverse_max(node->right);
}


void  delete(NodePtr root1,NodePtr root2, int i)
{
    if(i==1)                                    //被删除节点是其父节点的右子树
    {
        if(root2->left==NULL&&root2->right==NULL)               //被删除节点没有左右子树
        {
            root1->right=NULL;
        }else   if(root2->left!=NULL&&root2->right==NULL)       //被删除节点有左子树
        {
            root1->right=root2->left;
        }else   if(root2->right!=NULL&&root2->left==NULL)       //被删除节点有右子树
        {
            root1->right=root2->right;
        }else                                                   //被删除节点有左右子树
        {
            NodePtr  r=Traverse_max(root2->left);               //查找被删除节点的左子树中最大值节点 或最大值节点的父节点
            if(r->right==NULL)
            {
                r->right=root2->right;
                root1->right=r;
            }else
            {
                NodePtr r2=r->right;
                r->right=r2->left;
                r2->left=root2->left;
                r2->right=root2->right;
                root1->right=r2;
            }
        }
    }else                                                       //被删除节点是其父节点的左子树
    {
        if(root2->left==NULL&&root2->right==NULL)               //被删除节点没有左右子树
        {
            root1->left=NULL;
        }else   if(root2->left!=NULL&&root2->right==NULL)       //被删除节点有左子树
        {
            root1->left=root2->left;
        }else   if(root2->right!=NULL&&root2->left==NULL)       //被删除节点有右子树
        {
            root1->left=root2->right;
        }else                                                   //被删除节点有左右子树
        {
            NodePtr  r=Traverse_max(root2->left);               //查找被删除节点的左子树中最大值节点 或最大值节点的父节点
            if(r->right==NULL)
            {
                r->right=root2->right;
                root1->left=r;
            }else
            {
                NodePtr r2=r->right;
                r->right=r2->left;
                r2->left=root2->left;
                r2->right=root2->right;
                root1->left=r2;
            }
        }
    }
    free(root2);
}

Status BST_delete(BinarySortTreePtr bt)
{
    ElemType e;
    printf("请输入要删除的节点：");
    scanf("%d",&e);

    NodePtr root=bt->root;
    if(!BST_search(bt->root,e))   {printf("树中没有要被删除的节点\n");return false;}         //没有要被删除的节点
    int i=Cmp(root,e);
    while(i)                            //找到要删除节点和其父节点
    {
        if(i==1)                        //在右子树查找
        {
            i=Cmp(root->right,e);
            if(i==3)
            {
                delete(root,root->right,1);
                break;
            }
            root=root->right;
        }
        else if(i==2)                   //在左子树查找
        {
            i=Cmp(root->left,e);
            if(i==3)
            {
                delete(root,root->left,2);
                break;
            }
            root=root->left;
        }else   if(i==3)                //删除根节点
        {
            NodePtr r1=NULL;
            if(root->left!=NULL)            r1=Traverse_max(root->left);
            else    if(root->right!=NULL)   {bt->root=root->right; break;   }
            else    {bt->root->value=0;  break;}
            if(r1->right==NULL)
            {
                r1->right=root->right;
                bt->root=r1;
                free(root);
            }else
            {
                NodePtr r2=r1->right;
                r1->right=r2->left;
                r2->left=root->left;
                r2->right=root->right;
                bt->root=r2;
                free(root);
            }
            break;
        }
    }
    return true;
}
