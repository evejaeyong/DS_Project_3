#include <iostream>
#include <fstream>
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
	if (graph == NULL) return false;
	if (vertex > graph->getSize()) return false;

	ofstream fout;
	fout.open("log.txt", ios::app);
	fout << "========BFS========\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph BFS result\n";
	fout << "startvertex: " << vertex << "\n";
	fout << vertex;
    queue<int> q;
	bool *visited = new bool[graph->getSize() + 1];
	fill(visited, visited + graph->getSize() + 1, false);
	
	visited[vertex] = true;
	q.push(vertex);
	int count = 0;

	while (!q.empty()) {
		int s = q.front();
		q.pop();

		map <int, int>* m = new map<int, int>;
		if (option == 'Y') graph->getAdjacentEdgesDirect(vertex, m);
		else graph->getAdjacentEdges(vertex, m);

		for (auto iter : *m) {
			if (!visited[iter.first]) {
				q.push(iter.first);
				visited[iter.first] = true;
			}
		}
		if(count != 0) fout << " -> " << vertex;
		count++;
		delete m;
	}
	fout << "=====================\n\n";
	delete[] visited;
}

bool DFS(Graph* graph, char option, int vertex) {
   if (graph == NULL) return false;
	if (vertex > graph->getSize()) return false;

	ofstream fout;
	fout.open("log.txt", ios::app);
	fout << "========DFS========\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph DFS result\n";
	fout << "startvertex: " << vertex << "\n";
	fout << vertex;
    stack<int> s;
	bool *visited = new bool[graph->getSize() + 1];
	fill(visited, visited + graph->getSize() + 1, false);
	
	visited[vertex] = true;
	s.push(vertex);
	int count = 0;

	while (!s.empty()) {
		int st = s.top();
		s.pop();

		map <int, int>* m = new map<int, int>;
		if (option == 'Y') graph->getAdjacentEdgesDirect(vertex, m);
		else graph->getAdjacentEdges(vertex, m);
		
		for (auto iter : *m) {
			if (!visited[iter.first]) {
				s.push(iter.first);
				visited[iter.first] = true;
			}
		}
		if(count != 0) fout << " -> " << vertex;
		count++;
		delete m;
	}
	fout << "=====================\n\n";
	delete[] visited;
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