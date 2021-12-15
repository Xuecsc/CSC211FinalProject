CC  = g++ -pthread
CXX = g++ -pthread

INCLUDES = 
CFLAGS   = -std=c++17 -g -Wall $(INCLUDES)
CXXFLAGS = -std=c++17 -g -Wall $(INCLUDES)
default: main
main: main.o resource.o decision.o resourcePageCreator.o
# header dependency
main.o: main.cpp resourcePageCreator.h decision.h resource.h
resource.o: resource.h resource.cpp
decision.o: decision.h decision.cpp
resourcePageCreator.o: resourcePageCreator.h resourcePageCreator.cpp decision.h resource.h
