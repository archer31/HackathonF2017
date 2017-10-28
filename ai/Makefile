## Author: Alexander Corley, Jacob Hanson, Ryan Lynn
## 10-28-2017

solve: main.o ai.o
	g++ main.o ai.o -o solve

main.o: main.cpp
	g++ -c main.cpp -o main.o

ai.o: ai.cpp ai.h
	g++ -c ai.cpp -o ai.o

clean:
	rm -f *.o solve

