#ifndef CONTROL_H
#define CONTROL_H

#include "Calendar.h"
#include "View.h"
#include "EventServer.h"

class Control
{
  public:
    // initialize fields and retrive events from server
    Control();
    // sends all events from calendars to server
    ~Control();
    //launch function that implements the program control flow
    void launch();

  private:
    //a School Calendar object
    Calendar schoolCal;
    //a Work Calendar object
    Calendar workCal;
    //a View object
    View view;
    // a EventServer Object
    EventServer es;
};

#endif