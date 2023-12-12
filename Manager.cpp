#include "Manager.h"
#include "GraphMethod.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Manager::Manager() {
	graph = nullptr;	
	fout.open("log.txt");	//, ios::app
	load = 0;	//Anything is not loaded
}

Manager::~Manager() {
	if(graph)	//if graph is loaded, delete graph
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
			while (line[num] != '\0' && line[num] != ' ') {
				command.push_back(line[num]);
				num++;
			}
			if (command == "LOAD") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				string filename;
				if (line[num] == '\0') printErrorCode(100);
				else {
					num++;
					while (line[num] != '\0') {			//file name
						filename.push_back(line[num]);
						num++;
					}
					if (filename.size() == 0) printErrorCode(100);	//if file doesn't exist
					else if (LOAD(filename.c_str())) {
						fout << "========LOAD=======\n";
						fout << "Success\n";
						fout << "===================\n\n";
					}
					else printErrorCode(100);		//LOAD Fail
				}
			}
			else if (command == "PRINT") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (!PRINT()) printErrorCode(200);	//PRINT Fail (Doesn't have graph data)
			}
			else if (command == "BFS") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (line[num++] == '\0') printErrorCode(300);			//Lack of function factors
				else if (line[num] == 'Y' || line[num] == 'N') {
					char option = line[num];
					num++;
					if (line[num] == '\0') printErrorCode(300);		//Lack of function factors
					else {
						string vertex;
						while (line[num] != '\0') vertex.push_back(line[num++]);

						if (!mBFS(option, stoi(vertex))) {			//BFS Fail
							fout.open("log.txt", ios::app);
							printErrorCode(300);
						}
					}
				}
				else printErrorCode(300);
				fout.open("log.txt", ios::app);
			}
			else if (command == "DFS") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (line[num++] == '\0') printErrorCode(400);			//Lack of function factors
				else if (line[num] == 'Y' || line[num] == 'N') {
					char option = line[num];
					num++;
					if (line[num] == '\0') printErrorCode(400);		//Lack of function factors
					else {
						string vertex;
						while (line[num] != '\0') vertex.push_back(line[num++]);

						if (!mDFS(option, stoi(vertex))) {
							fout.open("log.txt", ios::app);			//DFS Fail
							printErrorCode(400);
						}
					}
				}
				else printErrorCode(400);
				fout.open("log.txt", ios::app);
			}
			else if (command == "KWANGWOON") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (!mKwoonWoon(1)) printErrorCode(500);
			}
			else if (command == "KRUSKAL") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (!mKRUSKAL()) printErrorCode(600);
			}
			else if (command == "DIJKSTRA") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (line[num++] == '\0') printErrorCode(700);			//Lack of function factors
				else if (line[num] == 'Y' || line[num] == 'N') {
					char option = line[num];
					num++;
					if (line[num] == '\0') printErrorCode(700);		//Lack of function factors
					else {
						string vertex;
						while (line[num] != '\0') vertex.push_back(line[num++]);

						if (!mDIJKSTRA(option, stoi(vertex))) {
							fout.open("log.txt", ios::app);			//Dijkstra Fail
							printErrorCode(700);
						}
					}
				}
				else printErrorCode(700);
				fout.open("log.txt", ios::app);
			}
			else if (command == "BELLMANFORD") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (line[num++] == '\0') printErrorCode(800);			//Lack of function factors
				else if (line[num] == 'Y' || line[num] == 'N') {
					char option = line[num];
					num++;
					if (line[num] == '\0') printErrorCode(800);		//Lack of function factors
					else {
						num++;
						string s_vertex, e_vertex;
						while (line[num] != ' ' && line[num] != '\0') s_vertex.push_back(line[num++]);
						if (line[num] == '\0') printErrorCode(800);	//Lack of function factors
						else {
							num++;
							while (line[num] != '\0') e_vertex.push_back(line[num++]);

							if (!mBELLMANFORD(option, stoi(s_vertex), stoi(e_vertex))) {
								fout.open("log.txt", ios::app);			//Bellman-Ford Fail
								printErrorCode(800);
							}
						}
					}
				}
				else printErrorCode(800);
				fout.open("log.txt", ios::app);
			}
			else if (command == "FLOYD") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
				if (line[num++] == '\0') printErrorCode(900);			//Lack of function factors
				else if (line[num] == 'Y' || line[num] == 'N') {
					if (!mFLOYD(line[num])) {
						fout.open("log.txt", ios::app);			//Floyd Fail
						printErrorCode(900);
					}
				}
				else printErrorCode(900);
				
			}
			else if (command == "EXIT") {
				if (!fout.is_open()) fout.open("log.txt", ios::app);
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
		fgraph.ignore();
		if (m_type) {		//list
			graph = new ListGraph(m_type, size);
			string line;
			int from = 0;
			while (getline(fgraph, line)) {
				int num = 0;
				while (line[num] != '\0' && line[num] != ' ') num++;
				
				if (line[num] == ' ') {				//parsing to, weight
					string to, weight;
					num = 0;
					while (line[num] != ' ') {
						to.push_back(line[num]);		//to
						num++;
					}
					num++;
					while (line[num] != '\0') {
						weight.push_back(line[num]);	//weight
						num++;
					}
					graph->insertEdge(from, stoi(to), stoi(weight));
				}
				else from = stoi(line);
				
			}

		}
		else {				//matrix
			graph = new MatrixGraph(m_type, size);
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

	fout << "========PRINT=======\n";	//Print Graph Data
	graph->printGraph(&fout);
	fout << "====================\n\n";
	return true;
}

bool Manager::mBFS(char option, int vertex)	{
	if (fout.is_open()) fout.close();		//if log file is open
	if (BFS(graph, option, vertex)) return true;
	else return false;
}

bool Manager::mDFS(char option, int vertex)	{
	if (fout.is_open()) fout.close();		//if log file is open
	if (DFS(graph, option, vertex)) return true;
	else return false;
}

bool Manager::mDIJKSTRA(char option, int vertex) {
	if (fout.is_open()) fout.close();		//if log file is open
	if (Dijkstra(graph, option, vertex)) return true;
	else return false;
}

bool Manager::mKRUSKAL() {
	if (fout.is_open()) fout.close();		//if log file is open
	if (Kruskal(graph)) return true;
	else return false;
}

bool Manager::mBELLMANFORD(char option, int s_vertex, int e_vertex) {
	if (fout.is_open()) fout.close();		//if log file is open
	if (Bellmanford(graph, option, s_vertex, e_vertex)) return true;
	else return false;
}

bool Manager::mFLOYD(char option) {
	if (fout.is_open()) fout.close();		//if log file is open
	if (FLOYD(graph, option)) return true;
	else return false;
}

bool Manager::mKwoonWoon(int vertex) {
	if (fout.is_open()) fout.close();		//if log file is open
	if (KWANGWOON(graph, vertex)) return true;
	return false;
}

void Manager::printErrorCode(int n) {
	if (!fout.is_open()) fout.open("log.txt", ios::app);
	fout << "========ERROR=======" << endl;
	fout << n << endl;
	fout << "====================" << endl << endl;
}