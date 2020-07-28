#include "StrategyRunner.h"
#include "Strategies/RandomStrategy.h"
#include <iostream>

using namespace std;

int main()
{
    Strategy* str = new RandomStrategy();
    StrategyRunner sr(str);

    sr.RunPlan(6,3,10000);
    cout << sr.GetAnalyze();
}