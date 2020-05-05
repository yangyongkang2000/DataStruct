#include"BinHeap.h"
#include"make.h"
int main()
{
    Graph G=(Graph)malloc(31*sizeof(List));
    for(int i=0;i<31;G[i++]=(List)malloc(sizeof(struct Node)));
    make(G);
    Table T=(Table)malloc(31*sizeof(struct TableEntry));
    InitTable(1,G,T,30);
    Dijkstra(T,30,1000);
   for(int i=1;i<=30;i++)
   {
        PrintPath(i,T);
        printf("  %d",T[i].Dist);
    printf("\n");
   }
    
}