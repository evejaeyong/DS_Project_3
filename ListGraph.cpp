#include "ListGraph.h"
#include <iostream>
#include <utility>

ListGraph::ListGraph(bool type, int size) : Graph(type, size) {
	m_List = new map<int, int>;
    kw_graph = new vector<int>;
}

ListGraph::~ListGraph()	{
	delete m_List;
    delete kw_graph;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m) {        //Definition of getAdjacentEdges(No Direction == Undirected)
	
}

void ListGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m) {  //Definition of getAdjacentEdges(Directed graph)
	
}

void ListGraph::insertEdge(int from, int to, int weight) {              //Definition of insertEdge
	
}

bool ListGraph::printGraph(ofstream *fout) {                            //Definition of print Graph
	
}