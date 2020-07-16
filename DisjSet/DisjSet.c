#include "DisjSet.h"
void Initilialize(DisjSet S,int NumSets)
{
    for(int i=NumSets;i>0;S[i--]=-1);
}
void SetUnion(DisjSet S,SetType Root1,SetType Root2)
{
          if(S[Root1]<S[Root2])
          {
              S[Root2]=Root1;
          }else{
              if(S[Root1]==S[Root2])
              {
                  S[Root2]--;
              }
              S[Root1]=Root2;
          }
}
SetType Find(ElementType X,DisjSet S)
{
    if(S[X]<=0)
    {
        return X;
    }
    return S[X]=Find(S[X],S);
}
