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
    bool *visited = new bool[size];
    int *distance = new int[size];

    if (graph->getType()) {     //true == list
        visited[vertex] = true;
	    distance[vertex] = 0;
	    q.push(vertex);

        while (!q.empty()) {
		    int s = q.front();
		    q.pop();
		    /*for (auto u : gr[s]) {
			    if (visited[u]) continue;
			    visited[u] = true;
			    //cout << u << " ";
			    distance[u] = distance[s] + 1;
			    q.push(u);
		    }*/
	    }
    }
    else {                      //false == matrix

    }
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