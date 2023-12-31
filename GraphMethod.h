#ifndef _GRAPHMETHOD_H_
#define _GRAPHMETHOD_H_

#include "ListGraph.h"
#include "MatrixGraph.h"

bool BFS(Graph* graph, char option, int vertex);     
bool DFS(Graph* graph, char option,  int vertex);     
bool KWANGWOON(Graph* graph, int vertex);  
bool Kruskal(Graph* graph);
bool Dijkstra(Graph* graph, char option, int vertex);    //Dijkstra
bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex); //Bellman - Ford
bool FLOYD(Graph* graph, char option);   //FLoyd

void QuickSort(vector<pair<pair<int, int>, int>>* e, int left, int right);
void InsertionSort(vector<pair<pair<int, int>, int>>* e, int left, int right);
void Union(int vertex1, int vertex2, int* parent);
int Find(int vertex, int* parent);

int init(int* tree, int start, int end, int node);
void update(int* tree, int start, int end, int node, int index, int dif);

#endif
