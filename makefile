# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
STFOLDER = ./Strategies

GAME = Board.h Game.h Board.cpp Game.cpp
ANALYZER = GameAnalysis.h GameAnalysis.cpp AnalysisCollector.h AnalysisCollector.cpp StrategyRunner.h StrategyRunner.cpp
STRATEGIES = $(STFOLDER)/Strategy.h $(STFOLDER)/RandomStrategy.cpp $(STFOLDER)/RandomStrategy.h 

cmdGame.o: $(GAME) CmdExecuter.cpp
	$(CC) $(CFLAGS) $(GAME) CmdExecuter.cpp -o cmdGame.o

cmdAnalyzer.o: $(GAME) $(ANALYZER) $(STRATEGIES) CmdAnalyzer.cpp
	$(CC) $(CFLAGS) $(GAME) $(ANALYZER) $(STRATEGIES) CmdAnalyzer.cpp -o cmdAn.o