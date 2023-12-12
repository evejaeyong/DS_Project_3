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
#define INF 1000000000

using namespace std;

bool BFS(Graph* graph, char option, int vertex) {
	if (graph == NULL) return false;				//if doesn't have graph
	if (vertex > graph->getSize()) return false;

	ofstream fout;									//print format
	fout.open("log.txt", ios::app);				//output file
	fout << "========BFS========\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph BFS result\n";
	fout << "startvertex: " << vertex << "\n";
	fout << vertex;
    queue<int> q;
	bool *visited = new bool[graph->getSize() + 1];			//visited vertex
	fill(visited, visited + graph->getSize() + 1, false);
	
	visited[vertex] = true;
	q.push(vertex);												//first vertex
	int count = 0;

	while (!q.empty()) {
		int s = q.front();
		q.pop();

		map <int, int>* m = new map<int, int>;					//AdjacentEdge
		if (option == 'Y') graph->getAdjacentEdgesDirect(s, m);	//Direct
		else graph->getAdjacentEdges(s, m);						//Undirect

		for (auto iter : *m) {
			if (!visited[iter.first]) {
				q.push(iter.first);
				visited[iter.first] = true;
			}
		}
		if(count != 0) fout << " -> " << s;
		count++;
		delete m;
	}
	fout << "\n===================\n\n";
	delete[] visited;		//visited Unallocate
}

bool DFS(Graph* graph, char option, int vertex) {
	if (graph == NULL) return false;				//if doesn't have graph
	if (vertex > graph->getSize()) return false;

	ofstream fout;									//print format
	fout.open("log.txt", ios::app);
	fout << "========DFS========\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph DFS result\n";
	fout << "startvertex: " << vertex << "\n";
	fout << vertex;
    stack<int> s;
	bool *visited = new bool[graph->getSize() + 1];				//visited vertex
	fill(visited, visited + graph->getSize() + 1, false);
	
	visited[vertex] = true;										//first vertex
	s.push(vertex);

	while (!s.empty()) {
		int st = s.top();

		map <int, int>* m = new map<int, int>;
		if (option == 'Y') graph->getAdjacentEdgesDirect(st, m);	//Direct
		else graph->getAdjacentEdges(st, m);						//Undirect
		
		for (auto iter : *m) {
			if (!visited[iter.first]) {
				s.push(iter.first);
				visited[iter.first] = true;
				fout << " -> " << iter.first;
				break;
			}
			if (iter == *m->rbegin()) s.pop();
		}
		delete m;
	}
	fout << "\n===================\n\n";
	delete[] visited;		//visited Unallocate
}

bool Kruskal(Graph* graph) {
	return false;
}

bool Dijkstra(Graph* graph, char option, int vertex) {
	if (graph == NULL) return false;				//if doesn't have graph
	if (vertex > graph->getSize()) return false;

	bool* s = new bool[graph->getSize() + 1];		//visited
	int* dist = new int[graph->getSize() + 1];		//distance
	int* prev = new int[graph->getSize() + 1];		//prev vertex

	fill(s, s + graph->getSize() + 1, false);
	fill(dist, dist + graph->getSize() + 1, INF);
	fill(prev, prev + graph->getSize() + 1, -1);

	map <int, int>* m = new map<int, int>;
	if (option == 'Y') graph->getAdjacentEdgesDirect(vertex, m);	//Direct
	else graph->getAdjacentEdges(vertex, m);						//Undirect

	for (auto iter : *m) {							//initialize
		if (iter.second < 0) {						//if negative edge
			delete[] s;
			delete[] dist;
			delete[] prev;
			delete m;
			return false;
		}
		dist[iter.first] = iter.second;
		prev[iter.first] = vertex;
		
	}
	delete m;

	s[vertex] = true;
	dist[vertex] = 0;
	prev[vertex] = 0;

	for (int i = 0; i < graph->getSize() - 2; i++) {
		int u = INF;

		for (int j = 1; j <= graph->getSize(); j++) {		//choose
			if (!s[j] && dist[j] != INF) u = j;
		}

		if (u != INF) {
			s[u] = true;
			m = new map<int, int>;

			if (option == 'Y') graph->getAdjacentEdgesDirect(u, m);	//Direct
			else graph->getAdjacentEdges(u, m);						//Undirect

			for (auto iter : *m) {
				if (iter.second < 0) {						//if negative edge
					delete[] s;
					delete[] dist;
					delete[] prev;
					delete m;
					return false;
				}

				dist[iter.first] = min(dist[u] + iter.second, dist[iter.first]);	//minimum path
				if (dist[u] + iter.second <= dist[iter.first]) prev[iter.first] = u;
			}
			delete m;
		}
	}

	ofstream fout;									//print format
	fout.open("log.txt", ios::app);
	fout << "======Dijkstra======\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph Dijkstra result\n";
	fout << "startvertex: " << vertex;
	
	for (int i = 1; i <= graph->getSize(); i++) {
		if (i == vertex) continue;
		stack<int> s;
		int num = i;
		fout << "\n[" << i << "] ";					//vertex number

		while (num != vertex && prev[num] != -1) {
			s.push(num);
			num = prev[num];
		}

		if (prev[num] == -1) {
			fout << "x";
		}
		else {
			fout << vertex;
			while (!s.empty()) {
				fout << " -> " << s.top();
				s.pop();
			}

			fout << " (" << dist[i] << ")";
		}
	}
	fout << "\n=====================\n\n";

	delete[] s;
	delete[] dist;
	delete[] prev;
	return true;
}

bool Bellmanford(Graph* graph, char option, int s_vertex, int e_vertex) {
	if (graph == NULL) return false;				//if doesn't have graph
	if (s_vertex > graph->getSize()) return false;
	if (e_vertex > graph->getSize()) return false;

	int* dist = new int[graph->getSize() + 1];		//distance
	int* prev = new int[graph->getSize() + 1];		//prev vertex

	fill(dist, dist + graph->getSize() + 1, INF);
	fill(prev, prev + graph->getSize() + 1, -1);

	map <int, int>* m = new map<int, int>;
	if (option == 'Y') graph->getAdjacentEdgesDirect(s_vertex, m);	//Direct
	else graph->getAdjacentEdges(s_vertex, m);						//Undirect

	for (auto iter : *m) {							//initialize
		dist[iter.first] = iter.second;
		prev[iter.first] = s_vertex;
	}
	delete m;

	for (int k = 0; k < graph->getSize() - 2; k++) {		//이거맞는지모르게슴요
		vector<int> v;
		for (int i = 1; i <= graph->getSize(); i++) {
			if (dist[i] != INF) v.push_back(i);
		}

		for (int i = 0; i < v.size(); i++) {
			m = new map<int, int>;
			if (option == 'Y') graph->getAdjacentEdgesDirect(v[i], m);	//Direct
			else graph->getAdjacentEdges(v[i], m);						//Undirect

			for (auto iter : *m) {
				dist[iter.first] = min(dist[v[i]] + iter.second, dist[iter.first]);			//minimum path
				if (dist[v[i]] + iter.second <= dist[iter.first]) prev[iter.first] = v[i];
			}
			delete m;
		}
	}

	ofstream fout;									//print format
	fout.open("log.txt", ios::app);
	fout << "======Bellman-Ford======\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph Bellman-Ford result\n";

	stack<int> s;
	int num = e_vertex;

	while (num != s_vertex && prev[num] != -1) {
		s.push(num);
		num = prev[num];
	}

	if (dist[e_vertex] < 0) {
		fout << "x";
	}
	else {
		fout << s_vertex;
		while (!s.empty()) {
			fout << " -> " << s.top();
			s.pop();
		}
		fout << "\ncost: " << dist[e_vertex];
	}
	fout << "\n========================\n\n";
	
	delete[] dist;
	delete[] prev;
	return true;
}

bool FLOYD(Graph* graph, char option) {
	if (graph == nullptr) return false; 
	int** dist = new int* [graph->getSize() + 1];
	for (int i = 0; i < graph->getSize() + 1; i++) {
		dist[i] = new int[graph->getSize() + 1];
		fill(dist[i], dist[i] + graph->getSize() + 1, INF);
	}

	for (int i = 1; i <= graph->getSize(); i++) {				//initialize
		map <int, int>* m = new map<int, int>;
		if (option == 'Y') graph->getAdjacentEdgesDirect(i, m);	//Direct
		else graph->getAdjacentEdges(i, m);						//Undirect

		dist[i][i] = 0;
		for (auto iter : *m) {
			dist[i][iter.first] = iter.second;
		}
		delete m;
	}

	for (int k = 1; k <= graph->getSize(); k++) {
		for (int i = 1; i <= graph->getSize(); i++) {
			for (int j = 1; j <= graph->getSize(); j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);	//Floyd
			}
		}
	}

	for (int i = 1; i <= graph->getSize(); i++) {
		if (dist[i][i] < 0) {
			for (int j = 0; j <= graph->getSize(); j++) {
				delete[] dist[j];
			}
			delete[] dist;
			return false;
		}
	}
		
	ofstream fout;									//print format
	fout.open("log.txt", ios::app);
	fout << "========FLOYD========\n";
	if (option == 'Y') fout << "Directed ";
	else fout << "Undirected ";
	fout << "Graph FLOYD result\n";

	for (int i = 0; i <= graph->getSize(); i++) {		//first line
		if (i == 0) fout << '\t';
		else fout << "[" << i << "]\t";
	}
	fout << "\n";
	for (int i = 1; i <= graph->getSize(); i++) {
		for (int j = 0; j <= graph->getSize(); j++) {	
			if (j == 0) fout << "[" << i << "]\t";					//matrix no
			else if (dist[i][j] != INF) fout << dist[i][j] << "\t";	//distance
			else fout << "x\t";										//infinite
		}
		fout << "\n";
	}
	fout << "=====================\n\n";
	return true;
}

bool KWANGWOON(Graph* graph, int vertex) {
	return false;
}