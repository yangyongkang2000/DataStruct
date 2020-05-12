/*Dijkstra算法*/
#ifndef _Graph_H
#define _Graph_H
#include<stdio.h>
#define NotAVertex (-1)
#define Infinity INT32_MAX
#define False 0
#define True 1
typedef int Vertex;
typedef int DistType;
typedef struct Node* List;
typedef List *Graph;
typedef int Weight;
typedef struct TableEntry *Table;
struct Node {
    Vertex V;
    Weight w;
    struct Node* Next;
};
struct TableEntry
{
    List Header;
    int Known;
    DistType Dist;
    Vertex Path;
};
void InitTable(Vertex Start,Graph G,Table T,int NumVertex);
void PrintPath(Vertex V,Table T);
void Dijkstra(Table T,int NumVertex,int Size);
void ReadGraph(Graph G,Table T,int NumVertex);
int *Topsort(Graph G,int Size);
void MaximumPath(Graph G,int Size,Table T);
#endif