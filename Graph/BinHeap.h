#ifndef _BinHeap_H
#define _BinHeap_H
#include "Graph.h"
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;
PriorityQueue Initialize(int MaxElements);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType x,PriorityQueue H,Table T);
ElementType DeleteMin(PriorityQueue H,Table T);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void DelataKey(PriorityQueue H,int index,ElementType delta,Table T);
void Delete(PriorityQueue H,int index,Table T);
void BuildHeap(PriorityQueue H,ElementType *array,int start,int end,Table T);
struct HeapStruct 
{
    int Capacity;
    int size;
    ElementType *Elements;
};
#endif