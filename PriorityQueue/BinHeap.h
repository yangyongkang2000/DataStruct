#ifndef _BinHeam_H
#define _BinHeam_H
#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;
PriorityQueue Initialize(int MaxElements);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType x,PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void DelataKey(PriorityQueue H,int index,ElementType delta);
void Delete(PriorityQueue H,int index);
void BuildHeap(PriorityQueue H,ElementType *array,int start,int end);
struct HeapStruct 
{
    int Capacity;
    int size;
    ElementType *Elements;
};
#endif