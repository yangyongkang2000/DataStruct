#include"Queue.h"
#include"make.h"
#include <time.h>
int main()
{
    clock_t start=clock();
    Graph G=(Graph)malloc(5052*sizeof(List));
    for(int i=0;i<5052;G[i++]=(List)malloc(sizeof(struct Node)));
    make(G);
    Table T=(Table)malloc(5052*sizeof(struct TableEntry));;
   MaximumPath(G,5051,T);
   printf("%d\n",T[5051].Dist);
   printf("%f\n",(double)(clock()-start)/CLOCKS_PER_SEC);
}