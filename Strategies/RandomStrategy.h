#ifndef _RANDOM_STRATEGY_H
#define _RANDOM_STRATEGY_H

#include "Strategy.h"

class RandomStrategy:public Strategy
{
public:
RandomStrategy();
virtual Direction GetMove(const Board b);

private:
std::mt19937 seed;
std::uniform_int_distribution<> rnd;
};

#endif