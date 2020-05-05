#include<stdlib.h>
#include"Stack.h"
void MakeEmpty(Stack S) 
{
    S->TopOfStack=EmptyTos;
}
Stack CreateStack(int MaxElements)
{
    Stack S=(struct StackRecord*)malloc(sizeof(struct StackRecord));
    S->array=(ElementType *)malloc(MaxElements*sizeof(ElementType));
    S->Capacity=MaxElements;
    S->TopOfStack=EmptyTos;
    return S;
}
void DisposeStack(Stack S) 
{
    free(S->array);
    free(S);
}
int IsFull(Stack S) 
{
         return S->TopOfStack==S->Capacity;
}
void Push(ElementType x,Stack S)
{
    if(IsFull(S))
    {
        printf("Stack is Full\n");
        exit(1);
    }
    S->array[++S->TopOfStack]=x;
}
int IsEmpty(Stack S)
{
    return S->TopOfStack==EmptyTos;
}
void Pop(Stack S)
{
    IsEmpty(S)?printf("Stack is Empty\n"):S->TopOfStack--;
}
ElementType TopAndPop(Stack S) 
{
    if(IsEmpty(S))
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return S->array[S->TopOfStack--];
}
ElementType Top(Stack S) 
{
    if(IsEmpty(S))
    {
        printf("Stack is Empty\n");
        exit(1);
    }
    return S->array[S->TopOfStack];
}