#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include "Tree.h"
char string[1000];
void SearchTreeReadInText(SearchTree T,FILE *fp)
{
    if(T!=NULL)
    {SearchTreeReadInText(T->Left,fp);
    if(T->Left!=NULL)
    {
        sprintf(string,"DirectedEdge[%d,%d]\n",(int)T->Element,(int)T->Left->Element);
        fputs(string, fp);
    }
    if(T->Right!=NULL)
    {
        sprintf(string,"DirectedEdge[%d,%d]\n",(int)T->Element,(int)T->Right->Element);
        fputs(string,fp);
    }
    SearchTreeReadInText(T->Right,fp);
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    ElementType array[10000];
    for(int i=0;i<10000;array[i++]=(double)(rand()%100000));
    SearchTree T=CreateSearchTree(array,0,9999);
    FILE *fp=fopen("/Users/yangyongkang/Desktop/a.txt","w");
    SearchTreeReadInText(T,fp);
    fclose(fp);
}