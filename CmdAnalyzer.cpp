#include "StrategyRunner.h"
#include "Strategies/RandomStrategy.h"
#include <iostream>

using namespace std;

int main()
{
    Strategy* str = new RandomStrategy();
    StrategyRunner sr(str);

    sr.RunSingleGame(4,1);
    sr.RunSingleGame(4,1);
    sr.RunSingleGame(4,1);
    sr.RunSingleGame(4,1);
    sr.RunSingleGame(4,1);
    cout << sr.GetAnalyze();
}