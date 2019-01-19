#ifndef WORKEVENT_H
#define WORKEVENT_H

#include <string>

#include "Date.h"
#include "Event.h"

class WorkEvent : public Event {

public:
	WorkEvent(std::string name, int=0);
	~WorkEvent();

	bool operator<(Event &e);
};

#endif