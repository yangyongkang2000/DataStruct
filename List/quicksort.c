#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define r rand()%500+1
#define size 100
typedef int ElementType;
FILE *file;
char s[100];
void Swap(ElementType* a,ElementType* b)
{
    ElementType c;
    c=*a;
    *a=*b;
    *b=c;
}
void QuickSort(ElementType* array,int start,int end)
{    if(end>start)
    {
      int bench=array[start];
      int index=start;
      int spaceindex=start;
      for(int i=start+1;i<=end;i++)
      {
        if(array[i]<bench)
        {
            index==spaceindex?spaceindex=i:0;
            Swap(array+i,array+index++);
            for(int j=0;j<size;j++)
            {
              sprintf(s,"%d\n",array[j]);
              fputs(s,file);
            }
        }
      }
      if(array[spaceindex]<=array[index])
      {
        Swap(array+index,array+spaceindex);
        spaceindex=index;
      }
      QuickSort(array,start,spaceindex-1);
      QuickSort(array,spaceindex+1,end);
    }
}
int main()
{
  srand(time(NULL));
  file=fopen("/Users/yangyongkang/Desktop/a.txt","w");
  ElementType array[size];
  for(int i=0;i<size;i++)
  {
         sprintf(s,"%d\n",array[i]=r);
         fputs(s,file);
  }
   QuickSort(array,0,size-1);
    for(int i=0;i<size;i++)
    {
           sprintf(s,"%d\n",array[i]);
           fputs(s,file);
    }
   fclose(file);
   return 0;
}
