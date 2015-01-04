#include "Time.h"

using namespace std;

Time::Time(){
	
}

Time::Time(string time){
	if(time[2] == ':'){
		hours = atoi(time.substr(0,2).c_str());
		minutes = atoi(time.substr(3,2).c_str());
		if(time[5] == 'p') {hours += 12;}
	}
	else {
		hours = atoi(time.substr(0,1).c_str());
		minutes = atoi(time.substr(2,2).c_str());
		if(time[4] == 'p') {hours += 12;}
	}
}

ostream& operator<<(ostream& out, const Time& printer){
	
	if(printer.hours > 12){
		cout << (printer.hours-12) << ":";
		if(printer.minutes < 10){
			cout << "0" << printer.minutes;
		}
		else {cout << printer.minutes;}
		cout << "pm";
	}
	else {cout << printer.hours << ":";
		if(printer.minutes < 10){
			cout << "0" << printer.minutes;
		}
		else {cout << printer.minutes;}
		cout << "am";
	}
	return out;	
}

bool Time::operator<(Time secondTime){
	bool ret = false;
	if((hours < secondTime.hours) || (secondTime.hours == hours && minutes < secondTime.minutes)){
		ret = true;
	}
	return ret;
}

bool Time::operator>(Time secondTime){
	bool ret = false;
	if((hours > secondTime.hours) || (secondTime.hours == hours && minutes > secondTime.minutes)){
		ret = true;
	}
	return ret;
}

bool Time::operator==(Time secondTime){
	bool ret = false;
	if((hours == secondTime.hours) && (minutes == secondTime.minutes)) {ret = true;}
	return ret;
}

int Time::operator-(Time& secondTime){ //returns num Minutes
	int subHours = hours - secondTime.hours;
	int subMinutes = minutes - secondTime.minutes;
	return (60 * subHours) + subMinutes;
}

int Time::operator+(Time& secondTime){
	int subHours = hours + secondTime.hours;
	int subMinutes = minutes + secondTime.minutes;
	return (60 * subHours) + subMinutes;
}

Time Time::operator+(int minutesAdded){
	Time ret;
	ret.minutes = this->minutes;
	ret.hours = this->hours;
	ret.minutes += minutesAdded;
	while(ret.minutes >= 60){
		ret.minutes -= 60;
		ret.hours ++;
	}
	return ret;
}
