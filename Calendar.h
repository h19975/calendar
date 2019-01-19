#ifndef CALENDAR_H
#define CALENDAR_H
#include "Event.h"
#include <string>
#include "Array.h"
#include "List.h"

class Calendar
{
  public:
	//constructor for Calendar
  Calendar(std::string);
	//destructor for Calendar
	~Calendar();
	//add a new event to arr
	void add(Event *);
	//print out events details for calendar
	void format(std::string&);
	// this function calls copy function inside event
	void copyEvents(Array&);

  private:
  std::string calendarName;
	//stores all events currently in the calendar
	List<Event *> * events;
	//track the number of events currently in the calendar
	int numEvent;
};

#endif
