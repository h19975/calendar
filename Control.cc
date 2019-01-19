#include "Control.h"
#include "Event.h"
#include "SchoolEvent.h"
#include "WorkEvent.h"
#include <string>
#include "Calendar.h"
#include "View.h"
#include "EventServer.h"
#include "Array.h"
#include <iostream>

using namespace std;

Control::Control() : schoolCal("my SchoolCalendar"), workCal("my WorkCalendar")
{
  //declare two arrays and retrieves events accordingly
  Array schoolEvents;
  Array workEvents;
  es.retrieve(schoolEvents, workEvents);

  // add events inside each array to corresponding calendar
  for (int i = 0; i < schoolEvents.getSize(); i++)
  {
    schoolCal.add(schoolEvents.get(i));
  }
  for (int i = 0; i < workEvents.getSize(); i++)
  {
    workCal.add(workEvents.get(i));
  }
}

Control::~Control()
{
  // declare two arrays to copy events from calendars
  Array schoolEvents;
  Array workEvents;
  schoolCal.copyEvents(schoolEvents);
  workCal.copyEvents(workEvents);

  // send events to server
  es.update(schoolEvents, workEvents);
}

void Control::launch()
{
  int    priority, day, month, year, hour, minute;
  string eventName, eventType;
  int    menuSelection;
  while (1) {
      //print out menu and read user selection
      menuSelection = view.displayMenuAndReadSelection();
      //break if user selects exit
      if (menuSelection == 0) break;
      //continue if user selects add event
      else if (menuSelection == 1) {
          //collect event type
          view.collectEventType(eventType);
          //collect event info
          view.collectEventInfo(priority, day, month, year, hour, minute, eventName);
          //create new event based on user input and store it in the calendar
	        Event * event;
          if(eventType == "School"){
            event = new SchoolEvent(eventName, priority);
            event->setDate(day, month, year, hour, minute);
            schoolCal.add(event);
          } else {
            event = new WorkEvent(eventName, priority);
            event->setDate(day, month, year, hour, minute);
            workCal.add(event);
          }
      }
  }
  
  //print out all events in current calendar
  string s,w;
  
  schoolCal.format(s);
  view.simplePrint(s);
  workCal.format(w);
  view.simplePrint(w);
}