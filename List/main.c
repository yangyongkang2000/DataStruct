#include <stdio.h>
#include "List.h"
#include <stdlib.h>
#define Max(a,b) a>b?a:b;
int det(List L)
{
    int a[9];
    for(int i=0;i<9;i++)
    {
        a[i]=L->Element;
        L=L->next;
    }
    return a[0]*a[4]*a[8]-a[0]*a[5]*a[7]-a[1]*a[3]*a[8]+a[1]*a[5]*a[6]+a[2]*a[3]*a[7]-a[2]*a[4]*a[6];
}
int main()
{
    List *arrary=Permutations(9);
   int max=0;
    int n=Factorial(9);
   for(int i=0;i<n;i++)
   {
        max=Max(max,det(arrary[i]));
   }
  printf("%d\n",max);
}

