#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

#include "Event.h"

Event::Event(string name, int priority)
	: eventName(name), priority(priority) {}

Event::~Event(){}

void Event::setDate(int d, int m, int y, int hour, int minute) {
	date = Date(d, m, y, hour, minute);
}

void Event::format(string & outStr)
{
	stringstream ss;
	ss<<"Event Name: "<<eventName<<endl;
	ss<<"Event Priority: "<<priority<<endl;
	ss<<"Date of Event: "<<endl;
	string str = "";
	date.formatLong(str);
	ss << str;
	outStr = ss.str();
}

void Event::print()
{
	cout<<"Event Name: "<<eventName<<endl;
	cout<<"Event Priority: "<<priority<<endl;
	cout<<"Date of Event: "<<endl;
	date.printLong();
}

Date& Event::getDate()
{
	return date;
}

int Event::getPriority(){
	return priority;
}

void Event::setDate(Date& myDate)
{
	date = myDate;
}