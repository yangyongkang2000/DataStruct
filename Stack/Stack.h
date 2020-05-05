#define EmptyTos (-1)
typedef double ElementType;
struct StackRecord;
typedef struct StackRecord *Stack;
int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void MakeEmpty(Stack S);
void Push(ElementType x,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
void MakeEmpty(Stack S);
void DisposeStack(Stack S);
ElementType TopAndPop(Stack S);
ElementType Top(Stack S);
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *array;
};
