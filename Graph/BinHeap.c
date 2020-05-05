#include "BinHeap.h"
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
     H->Capacity=MaxElements+1;
     H->size=0;
     H->Elements=(ElementType *)malloc((MaxElements+1)*sizeof(ElementType));
     H->Elements[0]=0;
     return H;
}
int IsFull(PriorityQueue H)
{
        return H->size==H->Capacity?1:0;
}
int IsEmpty(PriorityQueue H)
{
    return H->size?0:1;
}
void Insert(ElementType x,PriorityQueue H,Table T)
{
    int i;
    if(IsFull(H))
    {
        printf("PriorityQueue is Full\n");
        return ;
    }
    for(i=++H->size;T[H->Elements[i/2]].Dist>T[x].Dist;i/=2)
    {
        H->Elements[i]=H->Elements[i/2];
    }
    H->Elements[i]=x;
}
ElementType FindMin(PriorityQueue H)
{
    if(IsEmpty(H))
    {
        printf("PriorityQueue is Empty\n");
        return 0;
    }
    return H->Elements[1];
}
ElementType DeleteMin(PriorityQueue H,Table T)
{
    int i,child;
    if(IsEmpty(H))
    {
        printf("PriorityQueue is Empty\n");
        return (ElementType)0;
    }
    ElementType MinElement=H->Elements[1],LastElement=H->Elements[H->size--];
    for(i=1;2*i<=H->size;i=child)
    {
        child=2*i;
        child+=(child!=H->size&&T[H->Elements[child+1]].Dist<T[H->Elements[child]].Dist?1:0);
        if(T[LastElement].Dist>T[H->Elements[child]].Dist)
        {
            H->Elements[i]=H->Elements[child];
        }
        else{
            break;
        }
    }
    H->Elements[i]=LastElement;
    return MinElement;
}
void DelataKey(PriorityQueue H,int index,ElementType delta,Table T)
{
    if(index>H->size||index<1)
    {
        return;
    }
    if(delta>0)
    {
        int value=T[H->Elements[index]].Dist+delta;
        int i=index;
        while(1)
       {
            if(i<<1>H->size)
            {
                T[H->Elements[i]].Dist=value;
                break;
            }else
            {
                if(i<<1==H->size)
                {
                    if(T[H->Elements[i<<1]].Dist<value)
                    {
                        H->Elements[i]=H->Elements[i<<1];
                        i<<=1;
                    }else{
                        T[H->Elements[i]].Dist=value;
                        break;
                    }
                }else{
                    int index=T[H->Elements[i<<1]].Dist>T[H->Elements[(i<<1)+1]].Dist?(i<<1)+1:i<<1;
                    if(value>T[H->Elements[index]].Dist)
                    {
                        H->Elements[i]=H->Elements[index];
                        i=index;
                    }else{
                        T[H->Elements[i]].Dist=value;
                        break;
                    }
                }
            }
        }
    }else if(delta<0)
    {
        int value=T[H->Elements[index]].Dist+delta;
         int i;
         for(i=index;T[H->Elements[i/2]].Dist>value;i/=2)
        {
           H->Elements[i]=H->Elements[i/2];
        }
        T[H->Elements[i]].Dist=value;
    }
}
void Delete(PriorityQueue H,int index,Table T)
{
    DelataKey(H,index,INT_MIN,T);
    DeleteMin(H,T);
}
void BuildHeap(PriorityQueue H,ElementType *array,int start,int end,Table T)
{
    for(int i=start;i<=end&&H->size<H->Capacity;Insert(array[i++],H,T));
}  
