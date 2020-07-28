#ifndef _STRATEGY_RUNNER_H
#define _STRATEGY_RUNNER_H

#include "AnalysisCollector.h"
#include <string>

class StrategyRunner
{
public:
StrategyRunner(Strategy* const);
void RunPlan(unsigned long, unsigned long, unsigned long);
std::string GetAnalyze()const;

private:
bool RunSingleGame(unsigned long, unsigned long);

Strategy *const m_strtgy;
AnalysisCollector m_analysis;
// Tolrance: how many repeated tries to get valid move before declaring failed game?
unsigned long m_toltrance;

};

#endif