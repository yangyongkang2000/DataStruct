#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max(a,b) (a>b?a:b)
struct Sequence {int seq[2];};
struct Information {int min;List list;};
typedef struct Sequence* Seq;
struct Information MinChain(Seq arrary,int size)
{
    List *permu=Permutations(size);
    int length=Factorial(size);
    List index,l = NULL;
    int s,T;
    int min=INT_MAX;
    for(int i=0;i<length;i++)
    {      
            index=permu[i];
            T=arrary[index->Element-1].seq[0]+arrary[index->Element-1].seq[1];
            s=arrary[index->Element-1].seq[0];
            index=index->next;
            for(int j=1;j<size;j++)
            {
                  s+=arrary[index->Element-1].seq[0];
                  T=arrary[index->Element-1].seq[1]+max(T,s);
                  index=index->next;
            }
            if(T<min)
            {
                    min=T;
                    l=permu[i];
            }
      }
       struct Information info;
       info.min=min;
       info.list=l;
    return info;
}
int main()
{
      struct Sequence arrary[10]={11,8,5,2,16,11,11,11,4,6,9,10,12,19,1,2,3,4,11,12};
    struct Information info;
      printf("%d\n",(info=MinChain(arrary, 10)).min);
    List l=info.list;
    for(int i=0;i<10;i++)
    {
        printf("%d->",l->Element);
        l=l->next;
    }
    printf("\n");
    return 0;
}
