#ifndef _STRATEGY_H
#define _STRATEGY_H

#include "../Game.h"

class Strategy
{
public:
    virtual Direction GetMove(const Board b)=0;
};

#endif