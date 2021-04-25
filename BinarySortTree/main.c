#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

extern void SearchNode(NodePtr root);                               //查询节点
extern BinarySortTreePtr BST_insert(BinarySortTreePtr bt);
extern Status BST_delete(BinarySortTreePtr bt);
extern Status BST_preorderR(NodePtr root, void (*visit)(NodePtr));	//先序非递归遍历
extern Status BST_inorderR(NodePtr root, void (*visit)(NodePtr));	//中序非递归遍历
extern Status BST_postorderR(NodePtr root, void (*visit)(NodePtr));	//后序非递归遍历
extern Status BST_levelOrder(NodePtr root, void (*visit)(NodePtr));	//层序遍历
extern void InterFace();

Status Cmp(NodePtr root ,ElemType e)            //比较节点大小
{
    if(root==NULL)  return 0;
    if(root->value<e)   return 1;
    else    if(root->value>e)        return 2;
    return 3;
}

void visit(NodePtr e)
{
	printf("%d ",e->value);
}

BinarySortTreePtr BST_init(BinarySortTreePtr bt)                //初始化
{
    bt=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
    bt->root=(NodePtr)malloc(sizeof(Node));
    bt->root->value=0;
    bt->root->left=NULL;
    bt->root->right=NULL;
    return bt;
}

Status BST_preorderI(NodePtr root,void (*visit)(NodePtr e))     //先序递归遍历
{
    if(root==NULL)    return false;
    visit(root);
    BST_preorderI(root->left,visit);
    BST_preorderI(root->right,visit);
    return true;
}

Status BST_inorderI(NodePtr root, void (*visit)(NodePtr))	    //中序递归遍历
{
    if(root==NULL)  return 0;
    BST_inorderI(root->left,visit);
    visit(root);
    BST_inorderI(root->right,visit);
    return 1;
}

Status BST_postorderI(NodePtr root, void (*visit)(NodePtr))	//后序递归遍历
{
    if(root==NULL)  return 0;
    BST_postorderI(root->left,visit);
    BST_postorderI(root->right,visit);
    visit(root);
    return 1;
}

int main()
{
    /*BinarySortTreePtr bt;
    bt=BST_init(bt);
    //printf("%d\n",bt->root->value);
    bt=BST_insert(bt,10);
    bt=BST_insert(bt,5);
    bt=BST_insert(bt,16);
    bt=BST_insert(bt,3);
    bt=BST_insert(bt,1);
    bt=BST_insert(bt,4);
    bt=BST_insert(bt,8);
    bt=BST_insert(bt,9);
    bt=BST_insert(bt,6);
    bt=BST_insert(bt,7);
    bt=BST_insert(bt,13);
    bt=BST_insert(bt,14);
    bt=BST_insert(bt,20);
    bt=BST_insert(bt,22);
    bt=BST_insert(bt,18);
    //printf("%d\n",bt->root->value);
    BST_levelOrder(bt->root,visit);*/
    BinarySortTreePtr bt;
    bt=BST_init(bt);
    int p=1,i;
    char c[20];
    while(p!=0)
    {
        i=0;
        int t=1;
        InterFace();
        scanf("%s",c);
        if(strlen(c)>2) printf("Your input is error!\n");
        else
        {
            for(int j=0;j<strlen(c);j++)
            {
                i=(c[j]-'0')+i*t;
                t*=10;
            }
            switch(i)
            {
                case 1:bt=BST_insert(bt);break;
                case 2:SearchNode(bt->root);break;
                case 3:BST_delete(bt);break;
                case 4:BST_preorderI(bt->root,visit);break;
                case 5:BST_inorderI(bt->root,visit);break;
                case 6:BST_postorderI(bt->root,visit);break;
                case 7:BST_preorderR(bt->root,visit);break;
                case 8:BST_inorderR(bt->root,visit);break;
                case 9:BST_postorderR(bt->root,visit);break;
                case 10:BST_levelOrder(bt->root,visit);break;
                case 0:p=0;break;
                default:printf("Your input is error!\n");
            }
        }
    }
    return 0;
}

