
all:	Program3


Program3:	Program3.o Time.o Date.o Graph.o
	g++ -o Program3 Program3.o Time.o Date.o Graph.o


Program3.o:	Program3.cpp
	g++ -std=c++11 -c -g Program3.cpp

Time.o:		Time.cpp
	g++ -std=c++11 -c -g Time.cpp
	
Date.o:		Date.cpp
	g++ -std=c++11 -c -g Date.cpp

Graph.o:	Graph.cpp
	g++ -std=c++11 -c -g Graph.cpp

clean:
	rm -f *.o *~ Program3
