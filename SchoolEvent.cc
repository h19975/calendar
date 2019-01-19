#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

#include "SchoolEvent.h"

SchoolEvent::SchoolEvent(string name, int priority)
	: Event(name, priority){}

SchoolEvent::~SchoolEvent(){}

bool SchoolEvent::operator<(Event &e){
	return date < e.getDate();
}