bin/scheck: main.o parser.o
	g++ main.o parser.o -o bin/scheck

parser.o : src/parser.cpp inc/parser.h inc/error.h 
	g++ -I inc -c src/parser.cpp

main.o : src/main.cpp inc/parser.h inc/error.h inc/dictionary.h
	g++ -I inc -c src/main.cpp