#include "MatrixGraph.h"
#include <iostream>
#include <vector>
#include <string>

MatrixGraph::MatrixGraph(bool type, int size) : Graph(type, size) {
    m_Mat = new int* [size];
    for (int i = 0; i < size; i++) {
        m_Mat[i] = new int[size];
    }
}

MatrixGraph::~MatrixGraph() {
    for (int i = 0; i < m_Size; i++) {
        delete m_Mat[i];
    }
    delete m_Mat;
}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int>* m) {	

}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m) {
	
}

void MatrixGraph::insertEdge(int from, int to, int weight) {
	m_Mat[from][to] = weight;
}

bool MatrixGraph::printGraph(ofstream *fout) {
	
}
