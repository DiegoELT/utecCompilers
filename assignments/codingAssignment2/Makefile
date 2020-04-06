CXX =  g++
CXXFLAGS = -Wall -g -std=c++11

main: main.o ../codingAssignment1/state.o ../codingAssignment1/alphabet.o ../codingAssignment1/automata.o
	$(CXX) $(CXXFLAGS) -o main main.o ../codingAssignment1/state.o ../codingAssignment1/alphabet.o ../codingAssignment1/automata.o

clean:
	rm *.o main ../codingAssignment1/*.o