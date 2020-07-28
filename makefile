# the compiler: gCXX for C program, define as g++ for C++
CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++14
STFOLDER = ./Strategies

GAME = Board.h Game.h Board.cpp Game.cpp
ANALYZER = GameAnalysis.h GameAnalysis.cpp AnalysisCollector.h AnalysisCollector.cpp StrategyRunner.h StrategyRunner.cpp
STRATEGIES = $(STFOLDER)/Strategy.h $(STFOLDER)/RandomStrategy.cpp $(STFOLDER)/RandomStrategy.h 

#####################
# Executables  
#####################

cmdGame: $(GAME) CmdExecuter.cpp
	$(CXX) $(CFLAGS) $(GAME) CmdExecuter.cpp -o cmdGame

cmdAnalyzer: $(GAME) $(ANALYZER) $(STRATEGIES) CmdAnalyzer.cpp
	$(CXX) $(CFLAGS) $(GAME) $(ANALYZER) $(STRATEGIES) CmdAnalyzer.cpp -o cmdAn

#####################
# Executables  
#####################