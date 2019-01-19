#ifndef DATE_H
#define DATE_H
#include "Time.h"
#include <string>

class Date
{
  public:
	//constructor for Date object
    Date(int=0, int=0, int=2000, int=0, int=0);
    //desctrucor for Date object
	~Date();
    //method used to set date field
	void set(int, int, int, int, int);
    //print time and date in short format. eg: 01:24:00 07/10/2018
	void formatShort(std::string&);
	//print time and date in long format. eg: 01:24:00 October 07, 2018
    void formatLong(std::string&);
	//compare two date, return true if current date is less than given date.
	bool operator<(Date&);
    void printShort();
    void printLong();

  private:
    int day;
    int month;
    int year;
	//find out the last day available in month
    int  lastDayInMonth();
	//find out if year is a leapyear
    bool leapYear();
    //time object that represent the time in the date
	Time time;
	//returns English word for month
    std::string getMonthStr();
};

#endif
