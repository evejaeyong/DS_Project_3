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
	*fout << "\t";
    for (int i = 1; i <= m_Size; i++) {
        *fout << "[" << i << "]\t";
    }

    for (int i = 1; i <= m_Size; i++) {
        for (int j = -1; j < m_Size; j++) {
            if (j == -1) *fout << "[" << i << "]\t";
            else *fout << m_Mat[i][j] << "\t";
        }
        *fout << "\n";
    }
    return true;
}
