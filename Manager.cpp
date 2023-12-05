#include "Manager.h"
#include "GraphMethod.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Manager::Manager() {
	graph = nullptr;	
	fout.open("log.txt", ios::app);
	load = 0;	//Anything is not loaded
}

Manager::~Manager() {
	if(load)	//if graph is loaded, delete graph
		delete graph;	
	if(fout.is_open())	//if fout is opened, close file
		fout.close();	//close log.txt File
}

void Manager::run(const char* command_txt) {
	ifstream fin;	//Command File Input File Stream
	fin.open(command_txt, ios_base::in);//File open with read mode
		
	if(!fin) { //If command File cannot be read, Print error
		fout << "command file open error" << endl;
		return;	//Return
	}
	else {
		string command;
		while (1) {
			fin >> command;
			if (command == "LOAD") {
				string filename;
				fin >> filename;
				if(!LOAD(filename.c_str())) {
					printErrorCode(100);
				}
			}
			else if (command == "PRINT") {

			}
			else if (command == "BFS") {
				
			}
			else if (command == "DFS") {
				
			}
			else if (command == "KWANGWOON") {
				
			}
			else if (command == "KRUSKAL") {
				
			}
			else if (command == "DIJKSTRA") {
				
			}
			else if (command == "BELLMANFORD") {
				
			}
			else if (command == "FLOYD") {
				
			}
			else if (command == "EXIT") {
				fout << "========EXIT=======\n";
				fout << "Success\n";
				fout << "===================\n\n";
				break;
			}
			else {
				printErrorCode(1000);
			}
		}
	}
	fin.close();
	return;
}

bool Manager::LOAD(const char* filename) {
	ifstream fgraph;
	fgraph.open(filename);			//graph file open

	if (!fgraph) return false;		//can't read file
	else {
		if (load == 1) delete graph;	//already graph exist
			
		char type;
		bool m_type;
		int size;
		fgraph >> type;

		if (type == 'L') m_type = true;		//List is true
		else m_type = false;				//Matrix is false

		fgraph >> size;

		if (m_type) {		//list
			Graph* graph = new ListGraph(m_type, size);



			//구현해야합니다...
			
		}
		else {				//matrix
			Graph* graph = new MatrixGraph(m_type, size);
			int num;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					fgraph >> num;
					graph->insertEdge(i, j, num);
				}
			}
		}

	}
	return true;
}

bool Manager::PRINT() {

}

bool Manager::mBFS(char option, int vertex)	{
	
}

bool Manager::mDFS(char option, int vertex)	{
	
}

bool Manager::mDIJKSTRA(char option, int vertex) {
	
}

bool Manager::mKRUSKAL() {
 	
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex) {
	
}

bool Manager::mFLOYD(char option) {
	
}

bool Manager::mKwoonWoon(int vertex) {
	
}

void Manager::printErrorCode(int n) {
	fout << "========ERROR=======" << endl;
	fout << n << endl;
	fout << "====================" << endl << endl;
}


