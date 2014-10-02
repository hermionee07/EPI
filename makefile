CXX=g++
CXX_FLAGS= -std=c++11 -Wall
DEPS = utilities.h
OBJ = main.o utilities.o 

%.o: %.cpp $(DEPS)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

all: $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $^
