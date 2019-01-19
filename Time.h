#ifndef TIME_H
#define TIME_H
#include <string>
class Time
{
  public:
	//constructor for Time
    Time(int=0, int=0, int=0);
	//method to set data field for given input
    void set(int, int, int);
	//print out Time. eg: 05:24:00
    void format(std::string&);
	//compare two times, return true is time is less than a given time
    bool operator<(Time&);
    // print out time
    void print();


  private:
    int hours;
    int minutes;
    int seconds;
	//convert time to seconds
    int convertToSecs();
};

#endif
