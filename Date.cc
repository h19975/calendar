#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y, int hour, int minute)
{
  set(d, m, y, hour, minute);
}

Date::~Date()
{
}

void Date::set(int d,int m,int y, int hour, int minute)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
  time = Time(hour, minute, 0);
}

void Date::formatShort(string& outStr)
{
  stringstream ss;
  ss<<setfill('0')<<setw(2)<<day<<"/"
      <<setfill('0')<<setw(2)<<month<<"/"
      <<setfill('0')<<setw(4)<<year<<endl;
  string str = "";
  time.format(str);
  ss << str;
  outStr = ss.str();
}

void Date::printLong()
{
  cout<<getMonthStr()<<" "<<day<<", "<<year<<endl;
  time.print();
}

void Date::printShort()
{
  cout<<setfill('0')<<setw(2)<<day<<"/"
      <<setfill('0')<<setw(2)<<month<<"/"
      <<setfill('0')<<setw(4)<<year<<endl;
  time.print();
}

void Date::formatLong(string & outStr) 
{
  stringstream ss;
  ss<<getMonthStr()<<" "<<day<<", "<<year<<endl;
  string str;
  time.format(str);
  ss << str;
  outStr = ss.str();
}

bool Date::operator<(Date& date)
{
	if (year != date.year) {
		return year < date.year;
	} else {
		if (month != date.month) {
			return month < date.month;
		} else {
			if (day != date.day) {
				return day < date.day;
			} else {
				return time < date.time;
			}
		}
	}
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

string Date::getMonthStr() 
{
  string monthStrings[] = { 
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December" };

  if ( month >= 1 && month <= 12 )
    return monthStrings[month-1];
  else
    return "Unknown";
}

