#include "BinHeap.h"
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