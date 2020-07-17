#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include <iostream>
#include <random>

enum Direction {LEFT, RIGHT, UP, DOWN};

class Game
{
public:
    Game(unsigned long size=4, unsigned long spice=1);
//    ~Game();

    bool Move(Direction d);
    bool IsMoveLegal(Direction d)const;

    bool GameOver()const;
    unsigned long CurrentScore()const;

    void PrintState()const;
    void BeginGame();
    const Board BoardState();

private:
    void SpiceUp(); 
    unsigned long GetBeginIndex(Direction d)const;
    void IncreaseIndex(Direction d, unsigned long &i)const;
    void DecreaseIndex(Direction d, unsigned long &i)const;
    unsigned long GetTileValue(Direction d, unsigned long index, unsigned long segment)const;
    void SetTileValue(Direction d, unsigned long index, unsigned long segment, unsigned long val);

    Board m_board; 
    unsigned long m_spiceSize;

    unsigned long m_score;
    bool m_gameOver;
    unsigned int m_numTiles;

    std::mt19937 seed;
    std::uniform_int_distribution<> rnd;
};

#endif