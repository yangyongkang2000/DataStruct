#ifndef _DisjSet_H
#define  _DisjSet_H
typedef int* DisjSet;
typedef int SetType;
typedef int ElementType;
void Initilialize(DisjSet S,int NumSets);
void SetUnion(DisjSet S,SetType Root1,SetType Root2);
SetType Find(ElementType X,DisjSet S);
#endif