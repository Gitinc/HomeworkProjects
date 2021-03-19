CC = c++
CFLAGS = -Wall

all: aufgabe14 aufgabe13 aufgabe12

aufgabe14: aufgabe14.cpp
	$(CC) $(CFLAGS) -o aufgabe14 aufgabe14.cpp

aufgabe13: aufgabe13.cpp bitmuster.cpp bitmuster.hpp
	$(CC) $(CFLAGS) -o aufgabe13 aufgabe13.cpp bitmuster.cpp

aufgabe12: aufgabe12.cpp bitmuster.cpp bitmuster.hpp
	$(CC) $(CFLAGS) -o aufgabe12 aufgabe12.cpp bitmuster.cpp

clean: 	
	rm aufgabe12 aufgabe13 aufgabe14

