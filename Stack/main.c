#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define frand() (double)rand()/(RAND_MAX+1.0)
int main()
{
      srand((unsigned int)time(NULL));
    Stack S=CreateStack(100);
    printf("%d,%d,%d\n",IsEmpty(S),IsFull(S),S->TopOfStack);
    for(int i=0;i<100;i++)
    {
        Push(frand(),S);
    }
    for(int i=0;i<100;printf("%d: %.4f ,",TopAndPop(S),i++));
    printf("%d\n",IsEmpty(S));
    int x=3;
    printf("%d\n",sizeof(x*3+6*0.5)==sizeof(double));
}
