#include "View.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int View::displayMenuAndReadSelection()
{
  int numOptions = 1;
  int selection  = -1;

  cout << endl;
  cout << "(1) Add event" << endl;
  cout << "(0) Exit" << endl;

  while (selection < 0 || selection > numOptions) {
    cout << "Enter your selection: ";
    cin  >> selection;
  }
  return selection;
}

void View::collectEventInfo(int& priority, int& day, int& month, int& year, int& hour, int& minute, string& eventName)
{
    cout << "please enter information for your event: "<<endl;

    cout << "event name: "<<endl;
    cin >> eventName;
    // ask user for priority
    cout << "event priority" << endl;
    cin >> priority;
    cout << "day:   ";
    cin  >> day;
    cout << "month:   ";
    cin  >> month;
    cout << "year:   ";
    cin  >> year;
    cout << "hour:   ";
    cin  >> hour;
    cout << "minute:   ";
    cin  >> minute;	
}

/*void View::printCal(Calendar cal)
{
    cal.print();
}*/

void View::simplePrint(string s)
{
    cout << s <<endl;
}

void View::collectEventType(string& eventType){
  while(1){
    string s;
    cout << "Please input event type (School or Work): " << endl;
    cin >> s;
    if((s == "School") || (s == "Work")) {
      stringstream ss(s);
      eventType = ss.str();
      break;
    }
    cout << "Unknown event type. Check if your input is valid. Select from 'School' or 'Work'." << endl;
  }
}