-------------------------------
Author of Calendar program
-------------------------------
Program author:
Revision author:

-------------------------------
purpose of Calendar program
-------------------------------
The Calendar program is used for users to track their active events for current calendar.
User is able to load and save their events to cloud server.
-------------------------------
list of source/header/data files
-------------------------------
source files: main.cc Time.cc Date.cc Event.cc Calendar.cc View.cc Control.cc SchoolEvent.cc WorkEvent.cc
header files: Time.h Date.h Event.h Calendar.h View.h Control.h List.h SchoolEvent.h WorkEvent.h Node.h Array.h EventServer.h
object files: EventServer.o Array.o
data files: in.txt readme.txt Makefile

-------------------------------
compilation
-------------------------------
This program include a Makefile. User should type "make" in command line to build the project first.
After successfully building the project, user can type in "./cal" to lauch the project.
After successfully lauching the project, user can follow the instruction provided to enter valid input and record a event to the calendar.
There is a test file already provided by author, user can type in "./cal < in.txt" to test the project.