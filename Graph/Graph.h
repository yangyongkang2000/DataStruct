/*Dijkstra算法*/
#ifndef _Graph_H
#define _Graph_H
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define NotAVertex (-1)
#define Infinity INT32_MAX
#define False 0
#define True 1
typedef int Vertex;
typedef int DistType;
typedef struct Node* List;
typedef List *Graph;
typedef int Weight;
typedef struct TableEntry* Table;
typedef struct GraphStruct* GraphPackage;
typedef int* DisjSet;
typedef int SetType;
typedef int ElementType;
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
struct GraphRule 
{
     Vertex U,V;
     Weight w;
};
struct GraphStruct
{
     struct GraphRule **list;
     int Length;
     struct GraphRule **SpanningTree;
} ;
void PrintPath(Vertex V,Table T);
void Dijkstra(GraphPackage gp,Vertex Start,int NumVertex,int Size);
int *Topsort(GraphPackage gp,int Size);
void MaximumPath(GraphPackage gp,int Size);
void Kruskal(GraphPackage gp,int NumVertex);
void TransGraph(GraphPackage gp,Graph G);
void FreeGraphPackage(GraphPackage gp);
#endif