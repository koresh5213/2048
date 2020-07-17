#ifndef _STRATEGYRUNNER_H
#define _STRATEGYRUNNER_H

#include "Game.h"
#include "Strategies/Strategy.h"
#include "GameAnalysis.h"
#include <string>
#include <list>
#

class AnalysisCollector
{
public:
AnalysisCollector();
std::string GetAnalysis()const;

public:
void AddStatistic(const GameAnalysis);
void AddSingleGame(unsigned long gameSize, unsigned long spiceSize, unsigned long score, bool falied=false);

private:
std::list<GameAnalysis> m_results;
};

#endif