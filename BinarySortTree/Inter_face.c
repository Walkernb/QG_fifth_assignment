/**
*   选项界面
*/

#include<stdio.h>
#include<stdlib.h>

void InterFace()
{
    int i;
    printf("\n\n");
    for(i=0;i<35;i++)   printf(" ");
    for(int i=0;i<40;i++)   printf("*");    printf("\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    1       插入数字                  ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    2       查找数字                  ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    3       删除数字                  ");       printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    4       递归前序遍历              ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    5       递归中序遍历              ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    6       递归后序遍历              ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    7       迭代前序遍历              ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    8       迭代中序遍历              ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    9       迭代后序遍历              ");     printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    10      层序遍历                  ");      printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    printf("*");
    printf("    0       退出                      ");      printf("*\n");

    for(i=0;i<35;i++)   printf(" ");
    for(int i=0;i<40;i++)   printf("*");    printf("\n");

    printf("输入相应的数字，执行对应的操作：");
}
