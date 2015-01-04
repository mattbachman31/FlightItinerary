#include "Time.h"
#include "Date.h"
#include "Graph.h"

using namespace std;

int main(){
	ifstream in;
	in.open("schedule.txt");
	Graph g1(in);
	in.close();
	  cout << "Please pick an option below, or type 'Q' to quit." << endl;
	  cout << " J" << endl;
	  cout << " F" << endl;
	  cout << " C" << endl;
	  cout << " S" << endl;
	  cout << " P" << endl;
	  string userInput, secondUserInput, thirdUserInput, fourthUserInput, date1, date2;
	  cin >> userInput;
	while (userInput != "Q") {
	  if (userInput == "P") {
	  g1.print();
	  }
	  else if (userInput == "J") {
	  //g1.j();
	  cout << "J option is not available" << endl;
	  }
	  else if (userInput == "F") {
	  //g1.f();
	  cout << "F option is not available" << endl;
	  }
	  else if (userInput == "C") {
	  //g1.c();
	  cout << "C option is not available" << endl;
	  }
	  else if (userInput == "S") {
	  cout << "Please Enter Starting City As Appears On DDFS" << endl;
	  cin >> userInput;
	  cout << "Please Enter Destination City As Appears on DDFS" << endl;
	  cin >> secondUserInput;
	  cout << "Please Enter Departure Date, MM/DD/YYYY" << endl;
	  cin >> date1;
	  cout << "Please Enter Earliest Flight Time For Outbound Trip (in format 7:00am or 10:14pm etc)" << endl;
	  cin >> thirdUserInput;
	  cout << "Please Enter Return Date, MM/DD/YYYY" << endl;
	  cin >> date2;
	  cout << "Please Enter Earliest Time For Return Trip, Same Format" << endl;
	  cin >> fourthUserInput;
	  cout << endl << "Departure Trip on " << date1 << ": " << endl;
	  g1.s(userInput, secondUserInput, thirdUserInput);
	  cout << endl << "Return Trip on " << date2 << ": " << endl;
	  g1.s(secondUserInput, userInput, fourthUserInput);
	  cout << endl;
	  }
	  else {
	  cout << "Not a valid option" << endl;
	  }
	  cout << "Please pick an option below, or type 'Q' to quit." << endl;
	  cout << " J" << endl;
	  cout << " F" << endl;
	  cout << " C" << endl;
	  cout << " S" << endl;
	  cout << " P" << endl;
	  cin >> userInput;
    }
	return 0;
}
