#ifndef _HashTable_H
#define _HashTable_H
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
typedef int KeyElementType;
typedef int ValueElementType;
typedef int Index;
struct ListNode;
struct HashTbl;
typedef struct ListNode *Position;
typedef struct ListNode *List;
typedef struct HashTbl *HashTable;
HashTable InitializeTable(int TableSize);
Position Find(KeyElementType Key ,HashTable H,Index (*Hash)(int,int));
void Insert(KeyElementType Key,ValueElementType Value,HashTable H,void (*Assume)(Position),Index (*Hash)(int,int ));
Index Hash(KeyElementType Key,int TableSize);
struct ListNode
{
      KeyElementType Key;
      ValueElementType Value;
      Position  Next;
};
struct HashTbl 
{
    int TableSize;
    List *TheList;
};
#endif