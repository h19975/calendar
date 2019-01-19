OPT = -Wall

cal:	main.o Date.o Time.o Event.o SchoolEvent.o WorkEvent.o Calendar.o Control.o View.o Array.o EventServer.o
	g++ $(OPT) -o cal main.o Date.o Time.o Event.o SchoolEvent.o WorkEvent.o Calendar.o View.o Control.o Array.o EventServer.o

main.o:	main.cc Date.h
	g++ $(OPT) -c main.cc

Date.o:	Date.cc Date.h
	g++ $(OPT) -c Date.cc

Time.o:	Time.cc Time.h
	g++ $(OPT) -c Time.cc

Event.o: Event.cc Event.h
	g++ $(OPT) -c Event.cc

SchoolEvent.o: SchoolEvent.cc SchoolEvent.h
	g++ $(OPT) -c SchoolEvent.cc

WorkEvent.o: WorkEvent.cc WorkEvent.h
	g++ $(OPT) -c WorkEvent.cc
	
Calendar.o: Calendar.cc Calendar.h
	g++ $(OPT) -c Calendar.cc

Control.o: Control.cc Control.h
	g++ $(OPT) -c Control.cc

View.o: View.cc View.h
	g++ $(OPT) -c View.cc

clean:
	rm -f *.o cal