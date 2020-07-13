#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include <iostream>
#include <random>

enum Direction {LEFT, RIGHT, UP, DOWN};

class Game
{
public:
    Game(unsigned short size=4);
//    ~Game();

    bool Move(Direction d);

    bool GameOver()const;
    unsigned long CurrentScore()const;

    void PrintState()const;
    void BeginGame();
private:
    
    void SpiceUp(); 
    unsigned short GetBeginIndex(Direction d)const;
    void IncreaseIndex(Direction d, unsigned short &i)const;
    void DecreaseIndex(Direction d, unsigned short &i)const;
    unsigned short GetTileValue(Direction d, unsigned short index, unsigned short segment)const;
    void SetTileValue(Direction d, unsigned short index, unsigned short segment, unsigned short val);
    

    Board m_board; 

    unsigned long m_score;
    unsigned int m_numTiles;
    
    bool m_gameOver;

    std::mt19937 seed;
    std::uniform_int_distribution<> rnd;
};

#endif