CC  = g++
CXX = g++

INCLUDES = 
CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)


default: main
main: main.o Point.o 
# header dependency
main.o: main.cpp
Point.o: Point.h Point.cpp
.PHONY: clean
clean:
	rm -f *.o *~
