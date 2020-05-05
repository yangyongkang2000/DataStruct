#include "List.h"
#include<stdlib.h>
#include<stdio.h>
int Factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n*Factorial(n-1);
}
List *Permutations(int n)
{
      if(n==1)
      {
          List arrary[1]={NULL};
          Position p=(Position)malloc(sizeof(struct Node));
          p->Element=1;
          p->next=NULL;
          arrary[0]=p;
          return arrary;
      }
      List *list=(List *)calloc(Factorial(n),sizeof(struct Node));
      int size=0;
      int length=Factorial(n-1);
      List *array=Permutations(n-1);
      for(int i=0;i<length;i++)
    {
          List L=array[i];
          Position p=L;
          list[size++]=CopyList(InsertHead(n,L));
          for(int i=0;i<n-1;i++)
          {
              Insert(n,L,p);
              list[size++]=CopyList(L);
              Remove(p,L);
              p=p->next;
          }
          free(L);
          L=NULL;
    }
    return list;
}

