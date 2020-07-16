#include "Queue.h"
void FreeGraphPackage(GraphPackage gp)
{
        for(int i=0;i<gp->Length;free(gp->list[i++]));
        free(gp->list);
        free(gp);
}
void TransGraph(GraphPackage gp,Graph G)
{
    struct GraphRule * tmp;
    List tmp1,tmp2;
        for(int i=0;i<gp->Length;i++)
        {
            if(G[(tmp=gp->list[i])->U]->Next==NULL)
            {
            
                 G[tmp->U]->Next=(List)malloc(sizeof(struct Node));
                 G[tmp->U]->Next->V=tmp->V;
                 G[tmp->U]->Next->w=tmp->w;
                 G[tmp->U]->Next->Next=NULL;
            }else
            {
                tmp1=G[tmp->U]->Next;
                tmp2=(List)malloc(sizeof(struct Node));
                tmp2->V=tmp->V;
                 tmp2->w=tmp->w;
                 G[tmp->U]->Next=tmp2;
                 tmp2->Next=tmp1;
            }
        }
}
static void ReadGraph(Graph G,Table T,int NumVertex)
{
    int size=NumVertex+1;
    for(int i=0;i<size;i++)
    {
       T[i].Header=G[i];
    }
}
static void InitTable(Vertex Start,Graph G,Table T,int NumVertex)
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
void Dijkstra(GraphPackage gp,Vertex Start,int NumVertex,int Size)
{
    Graph G=(Graph)malloc((NumVertex+1)*sizeof(List));
    for(int i=0;i<NumVertex+1;G[i++]=(List)malloc(sizeof(struct Node)));
    TransGraph(gp,G);
    Table T=(Table)malloc((NumVertex+1)*sizeof(struct TableEntry));
    InitTable(Start,G,T,NumVertex);
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
       Weight Cvw=next->w;
       while(next!=NULL)
       {
           W=next->V;
             if(!T[W].Known&&T[V].Dist+Cvw<T[W].Dist)
             {
                 T[W].Dist=T[V].Dist+Cvw;
                 Insert(W,H,T);
                 T[W].Path=V;
             }
             next=next->Next;
             Cvw=next->w;
       }
    }
}
int *Topsort(GraphPackage gp,int Size)
{
    Graph G=(Graph)malloc((Size+1)*sizeof(List));
    for(int i=0;i<Size+1;G[i++]=(List)malloc(sizeof(struct Node)));
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
void MaximumPath(GraphPackage gp,int Size)
{
    Graph G=(Graph)malloc((Size+1)*sizeof(List));
    for(int i=0;i<Size+1;G[i++]=(List)malloc(sizeof(struct Node)));
    TransGraph(gp,G);
    Table T=(Table)malloc((Size+1)*sizeof(struct TableEntry));
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
            tmp=G[V]->Next;
            Cvw=tmp->w;
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
                tmp=tmp->Next;
                Cvw=tmp->w;
            }
        }
}
static void SetUnion1(DisjSet S,SetType Root1,SetType Root2)
{
          S[Root2]=Root1;
}
static SetType Find1(ElementType X,DisjSet S)
{
    if(S[X]<=0)
    {
        return X;
    }
    return Find1(S[X],S);
}
static int compar(const void *pt1,const void *pt2)
{
       return ((struct GraphRule*)pt1)->w>((struct GraphRule*)pt2)->w?1:-1;
}
void Kruskal(GraphPackage gp,int NumVertex)
{
    gp->SpanningTree=(struct GraphRule**)malloc((NumVertex-1)*sizeof(struct GraphRule*));
    int EdgesAccepeted=0,index=0;
   DisjSet S=(DisjSet)calloc(NumVertex+1,sizeof(SetType));
    Vertex U,V;
    struct GraphRule *E;
   qsort(gp->list,gp->Length,sizeof(struct GraphRule*),compar);
    while(EdgesAccepeted<NumVertex-1)
    {
          E=gp->list[index++];
          U=E->U;
          V=E->V;
          if(Find1(U,S)!=Find1(V,S))
          {
              SetUnion1(S,V,U);
              gp->SpanningTree[EdgesAccepeted++]=E;
          }
    }
}