#ifndef DATE
#define DATE

#include <iostream>
#include <string>
#include <ostream>
#include <cstdlib>

using namespace std;

class Date{
	public:
		Date();
		Date(string date);
		bool operator<(Date& secondDate);
		friend ostream& operator<<(ostream& out, const Date& printer);
	private:
		int day;
		int month;
		int year;
};
#endif
