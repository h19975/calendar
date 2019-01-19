#ifndef VIEW_H
#define VIEW_H
#include <string.h>
#include "Calendar.h"

class View
{
  public:
    //below function is used for displaying the main menu and reading the user’s selection
    int displayMenuAndReadSelection();
    //collectEventInfo is used for reading all the information from the user about one event
    void collectEventInfo(int&, int&, int&, int&, int&, int&, std::string&);
    //printing out the calendar
    //void printCal(Calendar);
    //for bonus
    void simplePrint(std::string); 
    // reading event type School or Work
  	void collectEventType(std::string& eventType);
};

#endif