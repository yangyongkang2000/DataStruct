#ifndef _Queue_h
#define _Queue_h
#include "BinHeap.h"
struct QueueRecord;
typedef struct QueueRecord *Queue;
int IsEmpty1(Queue Q);
int IsFull1(Queue Q);
Queue CreateQueue(int MaxElements);
void MakeEmpty1(Queue Q);
void Enqueue(ElementType x,Queue Q);
ElementType Dequeue(Queue Q);
void DisposeQueue(Queue Q);
struct QueueRecord 
{
      int Capacity;
      int Front;
      int Rear;
      int Size;
      ElementType *Array;
};
#endif