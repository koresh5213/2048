#ifndef _STRATEGY_RUNNER_H
#define _STRATEGY_RUNNER_H

#include "AnalysisCollector.h"
#include <string>

class StrategyRunner
{
public:
StrategyRunner(Strategy* const);
std::string RunPlan(std::string path);
std::string GetAnalyze()const;
bool RunSingleGame(unsigned long, unsigned long);

private:


Strategy *const m_strtgy;
AnalysisCollector m_analysis;
unsigned long m_toltrance;

};

#endif