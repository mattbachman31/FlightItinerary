#include "Graph.h"

using namespace std;

Graph::Graph(ifstream& in){
	char thing[200];
	int counter = 0;
	while(in.getline(thing, 200, '\n')){
		Edge *newEdge = new Edge();
		string line(thing);
		int firstSpaceIndex = line.find(' ');
		int secondSpaceIndex = line.find(' ', firstSpaceIndex+1);
		int thirdSpaceIndex = line.find(' ', secondSpaceIndex+1); 
		int fourthSpaceIndex = line.find(' ', thirdSpaceIndex+1);
		int end = line.find('\n', fourthSpaceIndex+1);
		string cityOne = line.substr(0,firstSpaceIndex);
		string cityTwo = line.substr(firstSpaceIndex+1,secondSpaceIndex - firstSpaceIndex - 1);
		string departureTime = line.substr(secondSpaceIndex+1, thirdSpaceIndex - secondSpaceIndex -1);
		string arrivalTime = line.substr(thirdSpaceIndex+1, fourthSpaceIndex - thirdSpaceIndex -1);
		string price = line.substr(fourthSpaceIndex+2, end - fourthSpaceIndex -2);
		int intPrice = atoi(price.c_str());
		newEdge->arrivalTime = Time(arrivalTime);
		newEdge->departureTime = Time(departureTime);
		newEdge->sourceCity = cityOne;
		newEdge->city = cityTwo;
		newEdge->price = intPrice;
		bool newCityOne = true;
		for(int i=0; i<cityNames.size(); i++){
			if(cityOne == cityNames[i].city) {newCityOne = false;}
		}
		if(newCityOne){
			Node add;
			add.city = cityOne;
			cityNames.push_back(add);
			counter++;
		}
		cityNames[counter-1].flights.push_back(newEdge);
	}
	
}
void Graph::print(){
	for(int j=0; j<cityNames.size(); j++){
		for (int k = 0; k<cityNames[j].flights.size(); k++){
			cout << cityNames[j].city;
			cout << " to ";
			Edge* blah = cityNames[j].flights[k];
			cout << blah->city;
			cout << " ";
			cout << blah->departureTime;
			cout << " ";
			cout << blah->arrivalTime;
			cout << " $";
			cout << blah->price << endl;
		}
	}
}

void Graph::s(string start, string destination, string startTimeInput){
	//minimizes time from their specified available starting time to arriving at destination
	Node* current;
	Node* first;
	Node* dest;
	int totalMinutes = 0;
	bool startFound=false, destFound=false;
	Time startTime(startTimeInput);
	unordered_map<string, int> distance;
	unordered_map<string, int> extracted; 
	for(vector<Node>::iterator it = cityNames.begin(); it != cityNames.end(); ++it){
		if(it->city == start) {
			current = &(*it);
			first = &(*it);
			distance.emplace(it->city,0);
			startFound = true;
		}
		else if(it->city == destination){
			destFound = true;
			distance.emplace(it->city,1000000);
		}
		else{
			distance.emplace(it->city,1000000);
		}
	}
	if(!(startFound && destFound)){
		cout << "Invalid Cities Given" << endl;
		return;
	}
	while(!(distance.empty()) && (extracted.size() != cityNames.size())){
		//search for smallest distance
		string smallest;
		pair<string, int> swapPair;
		int smallDist = 100000000; //infinity enough
		for(unordered_map<string, int>::iterator it=distance.begin(); it != distance.end(); ++it){
			if((*it).second < smallDist && (extracted.find(it->first) == extracted.end())){
				smallest = (*it).first;
				smallDist = (*it).second;
				swapPair = make_pair(smallest, smallDist);
			}
		}
		//smallest identified now do things
		for(vector<Node>::iterator it = cityNames.begin(); it != cityNames.end(); ++it){
			if(it->city == smallest) {
				current = &(*it);
			}
			if(it->city == destination) {
				dest = &(*it);
			}
		}
		//R-E-L-A-X @AaronRodgers
		for(vector<Edge*>::iterator it = current->flights.begin(); it != current->flights.end(); ++it){
			if(((distance.find((*it)->city))->second) > (((*it)->arrivalTime)-startTime)) {
				if(((*it)->departureTime) > (startTime+distance.find(smallest)->second) || ((*it)->departureTime) == (startTime+distance.find(smallest)->second)){
					distance.find((*it)->city)->second = (((*it)->arrivalTime)-startTime);
					//necessary to print out exact path, ruins O(N) complexity from presentation. Possibly smarter way?? Algorithm runs in O(N) w/o output
					for(vector<Node>::iterator it2 = cityNames.begin(); it2 != cityNames.end(); ++it2){
						if((*it)->city == it2->city){
							it2->prior = (*it);
						}
					}
				}
			}
		}
		extracted.insert(swapPair);
	}
	totalMinutes = extracted.find(destination)->second;		
	current = dest;
	int numHops = 0;
	int totalCost = recursivePrint(current, first, &numHops);
	cout << "Total Minutes of Trip, From Earliest Available Time to Arrival at Destination: " << totalMinutes << endl << "Total Cost of Trip: $" << totalCost << endl << "Total Number of Flights: " << numHops << endl;
	for(vector<Node>::iterator it = cityNames.begin(); it != cityNames.end(); ++it){
		it->prior = NULL;
	}
}

int Graph::recursivePrint(Node* current, Node* first, int* numHops){
	int cost = 0;
	if(current == first) {return 0;}
	if(current->prior != NULL){
		string temp = current->prior->sourceCity;
		Node* next;
		for(vector<Node>::iterator it = cityNames.begin(); it != cityNames.end(); ++it){
			if(it->city == temp){
				next = &(*it);
				break;
			}
		}
		cost += recursivePrint(next, first, numHops);
		(*numHops)++;
		cout << current->prior->sourceCity << " " << current->prior->city << " " << current->prior->departureTime << " " << current->prior->arrivalTime << " $" << current->prior->price << endl;
		cost += current->prior->price;
	}
	else{
		cout << "No possible one day trip beginning at specified start time." << endl;
	}
	return cost;
}

Graph::~Graph() {
 for (int j = 0; j<cityNames.size(); j++) {
  for (int i = 0; i<cityNames[j].flights.size(); i++) {
  delete cityNames[j].flights[i];
  }
 }  
}
