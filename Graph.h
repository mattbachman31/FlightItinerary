#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <utility>
#include "Time.h"
#include "Date.h"

using namespace std;

typedef struct{
	Time departureTime;
	Time arrivalTime;
	Date date;
	int price;
	string city; //destination
	string sourceCity;
}Edge;

typedef struct{
	string city;
	vector<Edge*> flights; //adjacency list
	Edge* prior = NULL;
}Node;

class Graph{
	public:
		Graph(ifstream& in);
		void j();
		void f();
		void c();
		void s(string start, string destination, string startTimeInput);
		void print();
		~Graph();	
	
	private:
		vector<Node> cityNames;
		int recursivePrint(Node* current, Node* first, int* numHops);
};

#endif
