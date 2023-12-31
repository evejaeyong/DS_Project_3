#include "ListGraph.h"
#include <iostream>
#include <utility>

ListGraph::ListGraph(bool type, int size) : Graph(type, size) {
	m_List = new map<int, int>[size];
    kw_graph = new vector<int>[size + 1];
}

ListGraph::~ListGraph()	{
	delete[] m_List;
    delete[] kw_graph;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m) {        //Definition of getAdjacentEdges(No Direction == Undirected)
	for (auto iter : m_List[vertex - 1]) {
		m->insert(iter);
	}

	for (int i = 0; i < m_Size; i++) {
		if (m_List[i].find(vertex) != m_List[i].end()) {
			m->insert({i + 1, m_List[i].find(vertex)->second});
		}
	}
}

void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m) {  //Definition of getAdjacentEdges(Directed graph)
	for (auto iter : m_List[vertex - 1]) {
		m->insert(iter);
	}
}

void ListGraph::insertEdge(int from, int to, int weight) {              //Definition of insertEdge
	m_List[from - 1].insert({to, weight});
	if (find(kw_graph[from].begin(), kw_graph[from].end(), to) == kw_graph[from].end()) kw_graph[from].push_back(to);
	if (find(kw_graph[to].begin(), kw_graph[to].end(), from) == kw_graph[to].end()) kw_graph[to].push_back(from);
}

bool ListGraph::printGraph(ofstream *fout) {                            //Definition of print Graph
	for (int i = 0; i < m_Size; i++) {
		*fout << "[" << i + 1 << "]";
		for (auto iter : m_List[i]) {
			*fout << " -> (" << iter.first << "," << iter.second << ")";
		}
		*fout << "\n";
	}
	return true;
}

vector<int>* ListGraph::Get_KW_Graph() {
	return kw_graph;
}