#include<stdlib.h>
#include<stdio.h>
#include "Tree.h"
int repeatCount=0;
SearchTree MakeEmpty(SearchTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
        T=NULL;
    }
    return NULL;
}
Position Find(ElementType x,SearchTree T)
{
    if(T==NULL)
    {
        printf("Element not Found\n");
        return NULL;
    }
    if(x<T->Element)
    {
        Find(x,T->Left);
    }
    if(x>T->Element)
    {
        Find(x,T->Right);
    }
    return T;
}
Position FindMax(SearchTree T)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(T->Right==NULL){
        return T;
    }
    return FindMax(T->Right);
}
Position  FindMin(SearchTree T)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(T->Left==NULL)
    {
        return T;
    }
    return FindMin(T->Left);
}
SearchTree Insert(ElementType x,SearchTree T)
{
    if(x==T->Element) {
        repeatCount++;
        return T;
    }
    if(x>T->Element) 
    { 
        if(T->Left==NULL)
      {
        T->Left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        T->Left->Element=x;
        T->Left->Left=NULL;
        T->Left->Right=NULL;
      }else
        {
        T->Left=Insert(x,T->Left);
        }  
    }else
    if(x<T->Element)
    {  if((T->Right)==NULL)
        {
            T->Right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            T->Right->Element=x;
            T->Right->Left=NULL;
            T->Right->Right=NULL;
        }else
       {
        T->Right=Insert(x,T->Right);
        }
    }
    return T;
}
SearchTree Delete(ElementType x,SearchTree T)
{
    if(T==NULL)
    {
        return T;
    }
    if(x==T->Element)
    {
        if(T->Left&&T->Right)
        {
            T->Element=FindMin(T->Left)->Element;
            T->Left=Delete(T->Element,T->Left);
        }else
        {
            if(T->Left!=NULL)
            {
                T->Element=T->Left->Element;
                T->Left=NULL;
            }
            if(T->Right!=NULL)
            {
                T->Element=T->Right->Element;
                T->Right=NULL;
            }
            T=NULL;
        }
    }
    if(x>T->Element)
    {
        T->Right=Delete(x,T->Right);
    }
    if(x<T->Element)
    {
        T->Left=Delete(x,T->Left);
    }
    return T;
}
void PrintTree(SearchTree T)
{
    if(T!=NULL)
    {
        PrintTree(T->Left);
        printf("%f\n",T->Element);
        PrintTree(T->Right);
    }
}
SearchTree CreateSearchTree(ElementType *array,int start,int end)
{
    SearchTree T=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    T->Element=array[start];
    T->Right=NULL;
    T->Left=NULL;
    for(int i=start+1;i<=end;i++)
    {
        Insert(array[i],T);
    }
    return T;
}
