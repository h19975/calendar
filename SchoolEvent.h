#ifndef SCHOOLEVENT_H
#define SCHOOLEVENT_H

#include <string>

#include "Date.h"
#include "Event.h"

class SchoolEvent : public Event {

public:
	SchoolEvent(std::string name, int=0);
	~SchoolEvent();

	bool operator<(Event &e);
};

#endif