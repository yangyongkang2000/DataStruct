#include "Queue.h"
Queue CreateQueue(int MaxElements)
{
    Queue Q=(Queue)malloc(sizeof(struct QueueRecord));
    Q->Capacity=MaxElements;
    Q->Front=1;
    Q->Rear=0;
    Q->Size=0;
    Q->Array=(ElementType *)malloc(MaxElements*sizeof(int));
    return Q;
}
int IsEmpty1(Queue Q)
{
    return Q->Size==0;
}
int IsFull1(Queue Q)
{
    return Q->Size==Q->Capacity;
}
void MakeEmpty1(Queue Q)
{
    Q->Size=0;
    Q->Front=1;
    Q->Rear=0;
}
static int Succ(int value,Queue Q)
{
    if(++value==Q->Capacity)
    {
         value=0;
    }
    return value;
}
void Enqueue(ElementType x,Queue Q)
{
    if(IsFull1(Q))
    {
        printf("Full Queue\n");
    }else
    {
        Q->Size++;
        Q->Rear=Succ(Q->Rear,Q);
        Q->Array[Q->Rear]=x;
    }
}
ElementType Dequeue(Queue Q)
{
    if(IsEmpty1(Q))
    {
        printf("Empty Queue\n");
        exit(1);
    }else
    {
        Q->Size--;
        Q->Front=Succ(Q->Front,Q);
    }
    return Q->Array[Q->Front-1];
}
void DisposeQueue(Queue Q)
{
    free(Q);
    Q=NULL;
}