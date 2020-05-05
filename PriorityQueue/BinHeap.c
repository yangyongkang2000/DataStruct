#include "BinHeap.h"
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H=(PriorityQueue)malloc(sizeof(struct HeapStruct));
     H->Capacity=MaxElements+1;
     H->size=0;
     H->Elements=(ElementType *)malloc((MaxElements+1)*sizeof(ElementType));
     H->Elements[0]=INT_MIN;
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
void Insert(ElementType x,PriorityQueue H)
{
    int i;
    if(IsFull(H))
    {
        printf("PriorityQueue is Full\n");
        return ;
    }
    for(i=++H->size;H->Elements[i/2]>x;i/=2)
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
ElementType DeleteMin(PriorityQueue H)
{
    ElementType min=FindMin(H);
    if(IsEmpty(H))
    {
        printf("PriorityQueue is Empty\n");
        return (ElementType)0;
    }
    int value=H->Elements[H->size--];
    int i=1;
    while(i>=H->size)
    {
            if(i<<1>H->size)
            {
                H->Elements[i]=value;
                break;
            }else
            {
                if(i<<1==H->size)
                {
                    if(H->Elements[i<<1]<value)
                    {
                        H->Elements[i]=H->Elements[i<<1];
                        i<<=1;
                    }else{
                        H->Elements[i]=value;
                        break;
                    }
                }else{
                    int index=H->Elements[i<<1]>H->Elements[(i<<1)+1]?(i<<1)+1:i<<1;
                    if(value>H->Elements[index])
                    {
                        H->Elements[i]=H->Elements[index];
                        i=index;
                    }else{
                        H->Elements[i]=value;
                        break;
                    }
                }
            }
    }
    return min;
}
void DelataKey(PriorityQueue H,int index,ElementType delta)
{
    if(index>H->size||index<1)
    {
        return;
    }
    if(delta>0)
    {
        int value=H->Elements[index]+delta;
        int i=index;
        while(1)
       {
            if(i<<1>H->size)
            {
                H->Elements[i]=value;
                break;
            }else
            {
                if(i<<1==H->size)
                {
                    if(H->Elements[i<<1]<value)
                    {
                        H->Elements[i]=H->Elements[i<<1];
                        i<<=1;
                    }else{
                        H->Elements[i]=value;
                        break;
                    }
                }else{
                    int index=H->Elements[i<<1]>H->Elements[(i<<1)+1]?(i<<1)+1:i<<1;
                    if(value>H->Elements[index])
                    {
                        H->Elements[i]=H->Elements[index];
                        i=index;
                    }else{
                        H->Elements[i]=value;
                        break;
                    }
                }
            }
        }
    }else if(delta<0)
    {
        int value=H->Elements[index]+delta;
         int i;
         for(i=index;H->Elements[i/2]>value;i/=2)
        {
           H->Elements[i]=H->Elements[i/2];
        }
        H->Elements[i]=value;
    }
}
void Delete(PriorityQueue H,int index)
{
    DelataKey(H,index,INT_MIN);
    DeleteMin(H);
}
void BuildHeap(PriorityQueue H,ElementType *array,int start,int end)
{
    for(int i=start;i<=end&&H->size<H->Capacity;Insert(array[i++],H));
}
