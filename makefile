CXX=g++
CXX_FLAGS= -std=c++11 -Wall -g3
DEPS = utilities.h primitiveTypes.h
OBJ = main.o utilities.o primitiveTypes.o
PROGRAM = epi.exe

%.o: %.cpp $(DEPS)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(PROGRAM): $(OBJ)
	$(CXX) $(CXX_FLAGS) -o $@ $^

clean:
	rm -f *.o $(PROGRAM)
