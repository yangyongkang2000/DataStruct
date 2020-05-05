#include <stdlib.h>
typedef int ElementType;
struct Node;
typedef struct Node *PtrNode;
typedef PtrNode Position;
typedef PtrNode List;
Position FindPrevious(ElementType x,List L);
void Insert(ElementType x,List L,Position p);
List InsertHead(ElementType x,List L);
void Remove(Position p,List L);
void Delete(ElementType x,List L);
List MakeEmpty(List L);
int IsEmpty(List L);
void DeleteList(List L);
List MakeList(ElementType *array,int start,int end);
List CopyList(List L);
List *Permutations(int n);
int Factorial(int n);
struct Node {
    ElementType Element;
    Position next;
};
