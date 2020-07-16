#include"Queue.h"
#include"make.h"
static unsigned long long int count=0;
void dfs(Graph G,Vertex V,Vertex W)
{
       if(V!=W)
       {
           List l=G[V]->Next;
           while(l!=NULL)
           {
               
               dfs(G,l->V,W);
               l=l->Next;
           }
       }else{
           count++;
       }
}
int main()
{
    GraphPackage gp=(GraphPackage)malloc(sizeof(struct GraphStruct));
    gp->Length=length;
    gp->list=(struct GraphRule**)malloc(length*sizeof(struct GraphRule*));
    for(int i=0;i<length;i++)
    {
        gp->list[i]=(struct GraphRule*)malloc(sizeof(struct GraphRule));
        gp->list[i]->U=matrix[i][0];
        gp->list[i]->V=matrix[i][1];
    }
   Graph G=(Graph)malloc((dim+1)*sizeof(List));
       for(int i=0;i<dim+1;G[i++]=(List)malloc(sizeof(struct Node)));
       TransGraph(gp,G);
       FreeGraphPackage(gp);
       dfs(G,1,dim);
       printf("%llu\n",count);
}