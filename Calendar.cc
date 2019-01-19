#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

#include "Calendar.h"
#include "List.h"

Calendar::Calendar(string name)
{
  calendarName = name;
  numEvent = 0;
  events = new List<Event *>();
}

Calendar::~Calendar()
{
	delete events;
}

void Calendar::add(Event *event)
{
	numEvent++;
	events->add(event);
}

void Calendar::format(string & outStr) {
	stringstream ss;
	ss<<"Printing all events for Calendar '"<<calendarName<<"':"<<endl;
	string str;
	events->format(str);
	ss << str;
	outStr = ss.str();
}

void Calendar::copyEvents(Array& arr)
{
	events->copy(arr);
}
	
			
					