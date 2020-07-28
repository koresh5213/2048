# 2048 Analyzer

I want to analyze the famous game, and find out which strategy works best.

## Project goals
Write any strategy you like, and get immidiate analysis.

Usage example:

```c++

#include "Strategies/MyStrategy1.h"
#include "Strategies/MyStrategy2.h"
#include <iostream>

using namespace std;

int main()
{
    Strategy s1();
    Strategy s2();
    
    StrategyRunner r1(&s1);
    StrategyRunner r2(&s2);

    s1.RunPlan(6,3,10000);
    s2.RunPlan(6,3,10000);
    
    cout << "Strategy1: " << s1.GetAnalyze();
    cout << "Strategy2: " << s2.GetAnalyze();
}

```

Output:

```
Strategy1:
Board size: 6
Spice size: 3
Number of games: 10000
Falled: 0
Avarage score: 8996.869600
Best score: 37072

Strategy2:
Board size: 6
Spice size: 3
Number of games: 10000
Falled: 2
Avarage score: 5326.7500
Best score: 120072

```

## Future features:
I am planning to provide the following:
- [ ] Runtime binding, so the analyzer can be pre-compiled
- [ ] 'Undo' function for game
- [ ] Provide 'hypothetical move'
