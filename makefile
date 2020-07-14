# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

GAME = Board.cpp Game.cpp Board.h Game.h

cmdGame.o: $(GAME) CmdExecuter.cpp
	$(CC) $(CFLAGS) $(GAME) CmdExecuter.cpp -o cmdGame.o