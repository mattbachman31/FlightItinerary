#include "Date.h"

using namespace std;

Date::Date(){

}

Date::Date(string date){
	day = atoi(date.substr(0,2).c_str());
	month = atoi(date.substr(3,2).c_str());
	year = atoi(date.substr(6,4).c_str());
}

ostream& operator<<(ostream& out, const Date& printer){
	if(printer.day < 10){
		cout << "0" << printer.day;
	}
	else {cout << printer.day;}
	cout << "/";
	if(printer.month < 10){
		cout << "0" << printer.month;
	}
	else {cout << printer.month;}
	cout << "/";
	cout << printer.year;
	return out;
}

bool Date::operator<(Date& secondDate){

}
