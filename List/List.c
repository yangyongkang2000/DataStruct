#include <stdio.h>
#include <stdlib.h>
#include "List.h"
int IsEmpty(List L) 
{
     return L==NULL;
}
void Insert(ElementType x,List L,Position p)
{
    if(IsEmpty(L))
    {
        printf("List is Empty\n");
        exit(1);
    }
    Position TempCell=(struct Node *)calloc(1,sizeof(struct Node));
    if(p->next!=NULL)
    {
        TempCell->Element=x;
        TempCell->next=p->next;
        p->next=TempCell;
    }else
    {
        TempCell->Element=x;
        TempCell->next=NULL;
        p->next=TempCell;
    }
}
List InsertHead(ElementType x,List L)
{
     Position TempCell=(Position)calloc(1,sizeof(struct Node));
     TempCell->Element=x;
     TempCell->next=L;
     return TempCell;
}
void Remove(Position p,List L) 
{
    if(p==NULL) 
    {
        printf("NULL\n");
        exit(2);
    }
    Position TmpCell=p->next;
    p->next=p->next->next;
    free(TmpCell);
    TmpCell=NULL;
}
Position FindPrevious(ElementType x,List L) 
{
    Position P=L;
    while(P->next!=NULL&&P->next->next->Element!=x) {
       P=P->next;
    }
    return P;
}
void Delete(ElementType x,List L) 
{
    Remove(FindPrevious(x,L),L);
}
void DeleteList(List L) 
{
    Position P,TmpCell;
    P=L;
    L->next=NULL;
    while(P!=NULL) 
    {
        TmpCell=P;
        P=P->next;
        free(TmpCell);
        TmpCell=NULL;
    }
}
List MakeList(ElementType *array,int start,int end) 
{
    List L=(struct Node*)malloc(sizeof(struct Node));
    Position P=L;
    Position TmpCell;
    L->Element=array[start];
    L->next=NULL;
    for(int i=start+1;i<=end;i++) 
    {
          Insert(array[i],L,P);
          P=P->next;
    }
    return L;
} 
List CopyList(List L)
{
       if(IsEmpty(L))
       {
           printf("List is Empty\n");
           exit(2);
       }
       List list=(List)malloc(sizeof(struct Node));
       list->Element=L->Element;
       L=L->next;
       Position p=list;
       while(L!=NULL)
       {
           p->next=(List)calloc(1,sizeof(struct Node));
           p=p->next;
           p->Element=L->Element;
           p->next=NULL;
           L=L->next;
           
       }
       return list;
}
