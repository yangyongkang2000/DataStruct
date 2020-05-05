#include "BinHeap.h"
#include<time.h>
#define Rand() rand()
#define Size 100
int main()
{
    FILE *file=fopen("/Users/yangyongkang/Desktop/a.txt","w");
    char s[100];
    srand((unsigned int)time(NULL));
    PriorityQueue H=Initialize(Size+1);
    ElementType a[Size];
    for(int i=0;i<Size;a[i++]=Rand());
    BuildHeap(H,a,0,Size-1);
    for(int i=1;i<=Size;i++)
    {
       if(i<<1<=H->size)
       {
           sprintf(s,"Rule[%d,%d]\n",H->Elements[i],H->Elements[i<<1]);
           fputs(s,file);
           if(H->size-(i<<1))
           {
               sprintf(s,"Rule[%d,%d]\n",H->Elements[i],H->Elements[(i<<1)+1]);
               fputs(s,file);
           }
       }
    }
    fclose(file);
}