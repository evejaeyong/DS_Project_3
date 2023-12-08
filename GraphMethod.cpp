#include <iostream>
#include <vector>
#include "GraphMethod.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <utility>

using namespace std;

bool BFS(Graph* graph, char option, int vertex) {
    queue<int> q;
    int size = graph->getSize();

   	//true == list
	bool *visited = new bool[size + 1];
	int *distance = new int[size + 1];

	visited[vertex] = true;
	distance[vertex] = 0;
	q.push(vertex);

	while (!q.empty()) {
		int s = q.front();
		q.pop();


	}
	delete visited;
	delete distance;
    
}

bool DFS(Graph* graph, char option, int vertex) {
   
}

bool Kruskal(Graph* graph) {
   
}

bool Dijkstra(Graph* graph, char option, int vertex) {
   
}

bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex) {
   
}

bool FLOYD(Graph* graph, char option) {
   
}

bool KWANGWOON(Graph* graph, int vertex) {

}