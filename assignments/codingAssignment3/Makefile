LXX = lex
CXX = g++
CXXFLAGS = -Wall -g

main: main.o lex.yy.c
	$(CXX) $(CXXFLAGS) -o main main.o lex.yy.c

lex.yy.c: basicScanner.l
	$(LXX) basicScanner.l

clean:
	rm *.o *.c main tokenTable.txt
	rm -r main.dSYM