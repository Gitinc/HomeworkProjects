CC = c++
CFLAGS = -Wall

all: aufgabe17 aufgabe18 aufgabe19

aufgabe17: aufgabe17.cpp lgc.cpp lgc.hpp
	$(CC) $(CFLAGS) -o aufgabe17 aufgabe17.cpp lgc.cpp


aufgabe18: aufgabe18.cpp MLCG.cpp MLCG.hpp lgc.cpp lgc.hpp
	$(CC) $(CFLAGS) -o aufgabe18 aufgabe18.cpp MLCG.cpp lgc.cpp

aufgabe19: aufgabe19.cpp MLCG.cpp MLCG.hpp lgc.cpp lgc.hpp
	$(CC) $(CFLAGS) -o aufgabe19 aufgabe19.cpp MLCG.cpp lgc.cpp

clean: 	
	rm aufgabe17 aufgabe18 aufgabe19
