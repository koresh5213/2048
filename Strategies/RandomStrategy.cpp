#include "RandomStrategy.h"
#include <random>

using namespace std;
RandomStrategy::RandomStrategy()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    seed = std::mt19937 (rd()); //Standard mersenne_twister_engine seeded with rd()
    rnd = std::uniform_int_distribution<> (0, 3);
}

Direction RandomStrategy::GetMove(const Board b)
{
    int c = rnd(seed);
    switch (c)
    {
    case 0:
        return UP;
    case 1:
        return DOWN;
    case 2:
        return LEFT;
    }
    return RIGHT;
}