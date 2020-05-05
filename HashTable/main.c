/*#include"HashTable.h"
void Assume(Position P)
{
    return;
}
int main()
{
    int n,k,count=0;
    scanf("%d %d",&n,&k);
    int *array=(int *)calloc(n,sizeof(int));
    HashTable H=InitializeTable(100003);
    for(int i=0;i<n;i++,array++)
    {
        scanf("%d",array);
        Insert(*array,1,H,Assume,Hash);
    }
    for(int i=0;i<n;i++,array--)
    {
        Position Q,P=Find(*array,H,Hash);
        P->Value=0;
        if((Q=Find(k-(*array),H,Hash))!=NULL)
        {
            if(Q->Value)
            {
                count++;
                Q->Value--;
            }
        }
    }
    printf("%d\n",count);
}*/
/*int main()
{
      HashTable H=InitializeTable(125261);
      for(int i=1;i<=500;i++)
      {
          for(int j=i;j<=500;j++)
          {
              Insert(i*i+j*j,1,H,Assume,Hash);
              if(Find(i*i+j*j,H,Hash)->Value==12)
              {
                  printf("%d\n",i*i+j*j);
                  return 0;
              }
          }
      }
}*/
#include<stdio.h>
#include<stdlib.h>
int Find(int *array,long long int element,int start,int end)
{
    if(end<start)
    {
        return 0;
    }
    if (element<array[start]||element>array[end])
    {
        return 0;
    }
    if (element==array[start]||element==array[end])
    {
        return 1;
    }
    int mid=(start+end)/2;
    if (element==array[mid])
    {
        return 1;
    }
    if(element<array[mid])
    {
        return Find(array,element,start,mid-1);
    }else{
        return Find(array,element,mid+1,end);
    }
}
int Comp(const void *a,const void*b)
{
    int m1=*(int *)a;
    int m2=*(int *)b;
    return m1>=m2?(m1==m2?0:1):-1;
}
int main()
{
    int n,k,count=0;
    scanf("%d %d",&n,&k);
    int *array=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",array+i);
    }
     qsort(array,n,sizeof(int),Comp);
     for(int i=0;i<n;i++)
     {
         count+=Find(array,k-array[i],i+1,n-1);
     }
     printf("%d",count);
}
