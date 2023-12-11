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
		while (1) {
			string line, command;
			int num = 0;
			getline(fin, line);
			while (line[num] != '\n' && line[num] != ' ') {
				command.push_back(line[num]);
				num++;
			}
			if (command == "LOAD") {
				string filename;
				num++;
				while (line[num] != '\n') {			//file name
					filename.push_back(line[num]);
					num++;
				}
				if (filename.size() == 0) printErrorCode(100);	//if file doesn't exist
				else if(LOAD(filename.c_str())) {
					fout << "========LOAD=======\n";
					fout << "Success\n";
					fout << "===================\n\n";
				}
				else printErrorCode(100);
			}
			else if (command == "PRINT") {
				if (!PRINT()) printErrorCode(200);
			}
			else if (command == "BFS") {
				num++;
				if (line[num] == 'Y' || line[num] == 'N') {
					char option = line[num];
					num++;
					if (line[num] == '\n') printErrorCode(300);
					else {
						string vertex;
						while (line[num] != '\n') vertex.push_back(line[num++]);

						if (!mBFS(option, stoi(vertex))) {
							fout.open("log.txt", ios::app);
							printErrorCode(300);
						}
					}
				}
				else printErrorCode(300);
			}
			else if (command == "DFS") {
				num++;
				if (line[num] == 'Y' || line[num] == 'N') {
					char option = line[num];
					num++;
					if (line[num] == '\n') printErrorCode(400);
					else {
						string vertex;
						while (line[num] != '\n') vertex.push_back(line[num++]);

						if (!mDFS(option, stoi(vertex))) {
							fout.open("log.txt", ios::app);
							printErrorCode(400);
						}
					}
				}
				else printErrorCode(400);
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
			string line;
			int from = 0;
			while (getline(fgraph, line)) {
				int num = 0;
				while (line[num] != '\n' && line[num] != ' ') num++;
				
				if (line[num] == ' ') {				//parsing to, weight
					string to, weight;
					num = 0;
					while (line[num] != ' ') {
						to.push_back(line[num]);
						num++;
					}
					num++;
					while (line[num] != '\n') {
						to.push_back(line[num]);
						num++;
					}
					graph->insertEdge(from, stoi(to), stoi(weight));
				}
				else from = stoi(line);
				
			}

		}
		else {				//matrix
			Graph* graph = new MatrixGraph(m_type, size);
			int num;
			for (int i = 1; i <= size; i++) {
				for (int j = 1; j <= size; j++) {
					fgraph >> num;
					graph->insertEdge(i, j, num);
				}
			}
		}

	}
	return true;
}

bool Manager::PRINT() {
	if (!graph) return false;

	fout << "========PRINT=======\n";
	graph->printGraph(&fout);
	fout << "====================\n\n";
	return true;
}

bool Manager::mBFS(char option, int vertex)	{
	fout.close();
	if (BFS(graph, option, vertex)) return true;
	else return false;
}

bool Manager::mDFS(char option, int vertex)	{
	fout.close();
	if (DFS(graph, option, vertex)) return true;
	else return false;
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


