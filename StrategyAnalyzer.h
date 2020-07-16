#ifndef _STRATEGYRUNNER_H
#define _STRATEGYRUNNER_H

#include "Game.h"
#include "Strategy.h"
#include <string>

class StrategyAnalyzer
{
public:
StrategyAnalyzer(Strategy* s);
std::string GetAnalysis()const;

private:
void RunSingleGame(unsigned long gameSize, unsigned long spiceSize);

private:
// Some data structure to save analises

Strategy* m_strategy;

};

#endif