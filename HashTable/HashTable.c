#include "HashTable.h"
static int hash;
HashTable InitializeTable(int TableSize)
{
    HashTable H=(HashTable)malloc(sizeof(struct HashTbl));
    H->TableSize=TableSize;
    H->TheList=(List*)malloc(sizeof(List)*TableSize);
    for(int i=0;i<TableSize;i++)
    {
        H->TheList[i]=(List)malloc(sizeof(struct ListNode));
        H->TheList[i]->Next=NULL;
    }
    return H;
}
Index Hash(KeyElementType Key,int TableSize)
{
           return abs(Key)%TableSize;
}
Position Find(KeyElementType Key ,HashTable H,Index (*Hash)(int,int ))
{

    Position P=H->TheList[hash=(*Hash)(Key,H->TableSize)]->Next;
    while(P!=NULL&&P->Key!=Key)
    {
        P=P->Next;
    }
    return P;
}
void Insert(KeyElementType Key,ValueElementType Value,HashTable H,void (*Assume)(Position),Index (*Hash)(int,int))
{
           Position P,New;
           List L;
          if((P=Find(Key,H,Hash))!=NULL)
          {
                  (*Assume)(P);
          }else
          {
                L=H->TheList[hash];
                 if(L->Next==NULL)
                 {
                     New=(Position)malloc(sizeof(struct ListNode));
                     New->Key=Key;
                     New->Next=NULL;
                     New->Value=Value;
                     L->Next=New;
                 }else{
                     New=(Position)malloc(sizeof(struct ListNode));
                     New->Key=Key;
                     New->Value=Value;
                    New->Next=L->Next;
                    L->Next=New;
                 }
          }
}