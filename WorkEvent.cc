#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

#include "WorkEvent.h"

WorkEvent::WorkEvent(string name, int priority)
	: Event(name, priority) {}

WorkEvent::~WorkEvent(){}

// for WorkEvent,lessThan is comparing the priority
bool WorkEvent::operator<(Event &e){
	// if priority is the same return date comaprison result
	if (priority == e.getPriority()) {
		return date < e.getDate();
	// else return priority comparison result
	} else {
		return priority < e.getPriority();
	}
}