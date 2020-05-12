#include "Queue.h"
void ReadGraph(Graph G,Table T,int NumVertex)
{
    int size=NumVertex+1;
    for(int i=0;i<size;i++)
    {
       T[i].Header=G[i];
    }
}
void InitTable(Vertex Start,Graph G,Table T,int NumVertex)
{
    int i;
    ReadGraph(G,T,NumVertex);
    int size=NumVertex+1;
    for(int i=0;i<size;i++)
    {
            T[i].Known=False;
            T[i].Dist=Infinity;
            T[i].Path=NotAVertex;
    }
    T[Start].Dist=0;
    T[0].Dist=INT32_MIN;
}
void PrintPath(Vertex V,Table T)
{
    if(T[V].Path!=NotAVertex)
    {
        PrintPath(T[V].Path,T);
        printf("->");
    }
    printf("%d",V);
}
void Dijkstra(Table T,int NumVertex,int Size)
{
    Vertex V,W;
    List next;
    int size=NumVertex+1;
    PriorityQueue H=Initialize(Size);
    int *array=(int *)malloc((size-1)*sizeof(int));
    for(int i=0;i<size-1;i++)
    {
        array[i]=i+1;
    }
    BuildHeap(H,array,0,size-2,T);
    for(;;)
    {
       while((V=DeleteMin(H,T)))
       {
           
           if(T[V].Known==False)
           {
               break;
           }
       }
       if(V==0||T[V].Dist==INT32_MIN)
       {
           break;
       }
       T[V].Known=True;
        List next=T[V].Header->Next;
       Weight Cvw=T[V].Header->w;
       while(next!=NULL)
       {
           W=next->V;
             if(!T[W].Known&&T[V].Dist+Cvw<T[W].Dist)
             {
                 T[W].Dist=T[V].Dist+Cvw;
                 Insert(W,H,T);
                 T[W].Path=V;
             }
             Cvw=next->w;
             next=next->Next;
       }
    }
}
int *Topsort(Graph G,int Size)
{
    int Counter=0;
    Queue Q=CreateQueue(Size);MakeEmpty1(Q);
    Vertex V,W;
    List tmp;
    int *Indegree=(int *)malloc((Size+1)*sizeof(int)),*TopNum=(int *)malloc((Size+1)*sizeof(int));
    for(int i=1;i<=Size;i++)
    {
        tmp=G[i]->Next;
        V=tmp->V;
        while(tmp!=NULL)
        {
             Indegree[V]++;
             tmp=tmp->Next;
        }
    }
        for(int i=1;i<=Size;i++)
        {
            if(Indegree[i]==0)
            {
                Enqueue(i,Q);
            }
        }
        while(!IsEmpty1(Q))
        {
            V=Dequeue(Q);
            TopNum[V]=++Counter;
            tmp=G[V]->Next;
            while (tmp!=NULL)
            {
                W=tmp->V;
               if(--Indegree[W]==0)
               {
                   Enqueue(W,Q);
               }
               tmp=tmp->Next;
            }
        }
        if(Counter!=Size)
        {
            printf("Graph has a cycle");
            exit(1);
        }
        DisposeQueue(Q);
    return TopNum;
}
static void InitTable1(Graph G,Table T,int NumVertex)
{
    int i;
    ReadGraph(G,T,NumVertex);
    int size=NumVertex+1;
    for(int i=0;i<size;i++)
    {
            T[i].Known=False;
            T[i].Dist=INT32_MIN;
            T[i].Path=NotAVertex;
    }
}
void MaximumPath(Graph G,int Size,Table T)
{
    InitTable1(G,T,Size);
    int Counter=0,first=0;
    Queue Q=CreateQueue(Size);MakeEmpty1(Q);
    Vertex V,W;
    List tmp;
    Weight Cvw;
    int *Indegree=(int *)malloc((Size+1)*sizeof(int));
    for(int i=1;i<=Size;i++)
    {
        tmp=G[i]->Next;
        while(tmp!=NULL)
        {
            V=tmp->V;
             Indegree[V]++;
             tmp=tmp->Next;
        }
    }
        for(int i=1;i<=Size;i++)
        {
            if(Indegree[i]==0)
            {
                Enqueue(i,Q);
            }
        }
        while(!IsEmpty1(Q))
        {
            V=Dequeue(Q);
            T[V].Dist=first++?T[V].Dist:0;
            Cvw=G[V]->w;
            tmp=G[V]->Next;
            while (tmp!=NULL)
            {
                W=tmp->V;
                if(T[V].Dist+Cvw>T[W].Dist)
             {
                 T[W].Dist=T[V].Dist+Cvw;
                 T[W].Path=V;
             }
               if(--Indegree[W]==0)
               {
                   Enqueue(W,Q);
               }
                Cvw=tmp->w;
                tmp=tmp->Next;
            }
        }
}
