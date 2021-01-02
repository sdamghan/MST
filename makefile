_SRC = ./src
_BIN = ./bin

CC = g++
CFLAG = -O0 -g -std=c++11 
_OBJ = hw3

all: main
	$(CC) $(CFLAG) $(_BIN)/*.o -o $(_OBJ)

main: mst graph
	$(CC) -c $(CFLAG) $(_SRC)/*.cpp $(_SRC)/*.hpp 
	mv *.o $(_BIN)
	rm $(_SRC)/*.gch

mst: graph $(_SRC)/mst.cpp $(_SRC)/mst.hpp
	$(CC) -c $(CFLAG) $(_SRC)/mst.cpp $(_SRC)/mst.hpp

graph: $(_SRC)/graph.cpp $(_SRC)/graph.hpp
	$(CC) -c $(CFLAG) $(_SRC)/graph.cpp $(_SRC)/graph.hpp

clean:
	rm -rf $(_BIN) $(_OBJ)
	mkdir $(_BIN)
	clear
