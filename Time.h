#ifndef TIME
#define TIME

#include <iostream>
#include <string>
#include <ostream>
#include <cstdlib>

using namespace std;

class Time{
	public:
		Time();
		Time(string time);
		int operator-(Time& secondTime);
		int operator+(Time& secondTime);
		Time operator+(int minutesAdded);
		//bool operator=(Time& secondTime);
		bool operator<(Time secondTime);
		bool operator>(Time secondTime);
		bool operator==(Time secondTime);
		friend ostream& operator<<(ostream& out, const Time& printer);
		//~Time();
	private:
		int hours;
		int minutes;
};

#endif
