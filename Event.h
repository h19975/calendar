#ifndef EVENT_H
#define EVENT_H
#include "Date.h"
#include <string>

class Event
{
  public:
		//constructor for Event
    Event(std::string name, int=0);
		// set date object
		void setDate(int=0, int=0, int=0, int=0, int=0);
		//method to print out event details
		void format(std::string&);
		void print();
		//return date data field
		Date& getDate();
		//return priority data field
		int getPriority();
		//set date data field
		void setDate(Date& date);
		// less than
		virtual bool operator<(Event &) = 0;
		virtual ~Event();

  protected:
    std::string eventName;
		//represent the date of the event
		Date date;
		//indicate the priority of current event
		int priority;
};

#endif