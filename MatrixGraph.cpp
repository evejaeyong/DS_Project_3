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
        delete[] m_Mat[i];
    }
    delete[] m_Mat;
}

void MatrixGraph::getAdjacentEdges(int vertex, map<int, int>* m) {	
    for (int i = 0; i < m_Size; i++) {
        if (m_Mat[vertex - 1][i] != 0) m->insert({i + 1, m_Mat[vertex - 1][i]});
        if (m_Mat[i][vertex - 1] != 0) m->insert({i + 1, m_Mat[i][vertex - 1]});
    }
}

void MatrixGraph::getAdjacentEdgesDirect(int vertex, map<int, int>* m) {
    for (int i = 0; i < m_Size; i++) {
        if (m_Mat[vertex - 1][i] != 0) m->insert({i + 1, m_Mat[vertex - 1][i]});
    }
}

void MatrixGraph::insertEdge(int from, int to, int weight) {
	m_Mat[from - 1][to - 1] = weight;
}

bool MatrixGraph::printGraph(ofstream *fout) {
	*fout << "\t";
    for (int i = 1; i <= m_Size; i++) {
        *fout << "[" << i << "]\t";
    }

    for (int i = 0; i < m_Size; i++) {
        for (int j = -1; j < m_Size; j++) {
            if (j == -1) *fout << "[" << i + 1 << "]\t";
            else *fout << m_Mat[i][j] << "\t";
        }
        *fout << "\n";
    }
    return true;
}
