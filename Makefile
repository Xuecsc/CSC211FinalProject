CC  = g++
CXX = g++

INCLUDES = 
CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)


default: main
main: main.o
# header dependency
main.o: main.cpp

.PHONY: clean
clean:
	rm -f *.o *~
