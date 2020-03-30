CXX =  g++
CXXFLAGS = -Wall -g -std=c++11

main: main.o state.o alphabet.o automata.o
	$(CXX) $(CXXFLAGS) -o main main.o state.o alphabet.o automata.o

clean:
	rm *.o main