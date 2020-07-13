#include "Game.h"
#include <iostream>
#include <random>

using namespace std;

Game::Game(unsigned short size)
: m_board(size)
, m_score(0)
, m_gameOver(false)
, m_numTiles(0)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    seed = std::mt19937 (rd()); //Standard mersenne_twister_engine seeded with rd()
    rnd = std::uniform_int_distribution<> (0, size-1);

    BeginGame();
}

void Game::SpiceUp()
{
    int randcol, randrow, randcol2, randrow2;

    if (m_numTiles > m_board.Size() * m_board.Size() -2 ) // No space for more tiles
    {
        m_gameOver = true;
        return;
    }

    do
    {
        randrow = rnd(seed);
        randcol = rnd(seed);
    } while ( m_board.GetTile(randrow, randcol) != 0 );
    
    m_board.SetTile(randrow, randcol, 2);
    m_numTiles++;

    do
    {
        randrow2 = rnd(seed);
        randcol2 = rnd(seed);
    } while ( m_board.GetTile(randrow2, randcol2) != 0 );
    
    m_board.SetTile(randrow2, randcol2, 2);
    m_numTiles++;
}

void Game::BeginGame()
{
    m_board.ClearBoard();
    m_numTiles = 0;
    m_score = 0;
    m_gameOver = false;
    SpiceUp();
}

void Game::PrintState()const
{
    cout << "Score: " << m_score << endl;
    cout << "Free tiles: " << m_board.Size() *m_board.Size() - m_numTiles << endl;
    m_board.PrintBoard();
}

bool Game::Move(Direction d)
{
    unsigned short segment; // The row or col, depends on direction
    unsigned short next, partner;

    for (segment = 0 ;segment < m_board.Size() ; ++segment)

        for (next = GetBeginIndex(d); next < m_board.Size() && next >= 0; IncreaseIndex(d, next))
        {
            partner = next;
            IncreaseIndex(d, partner);

            for (;partner < m_board.Size()  && partner >= 0; IncreaseIndex(d,partner))
            {
                if (GetTileValue(d, partner, segment) == 0)
                {
                    continue;
                }

                if (GetTileValue(d, next, segment) == 0)
                {
                    SetTileValue(d, next, segment, GetTileValue(d, partner, segment));
                    SetTileValue(d, partner, segment, 0);

                    DecreaseIndex(d,next);
                    break;
                }

                if (GetTileValue(d, next, segment) == GetTileValue(d, partner, segment))
                {
                    SetTileValue(d, next, segment, 2 * GetTileValue(d, partner, segment));
                    SetTileValue(d, partner, segment, 0);

                    m_numTiles--;
                    m_score += GetTileValue(d, next, segment);
                    break;
                }

                if ( abs(next-partner) == 1) // This means two different tiles with no '0's
                {
                    break;
                }

                IncreaseIndex(d, next);
                SetTileValue(d, next, segment, GetTileValue(d, partner, segment));
                SetTileValue(d, partner, segment, 0);
                DecreaseIndex(d,next);
                break;
            }
        }

    SpiceUp();
}

unsigned short Game::GetBeginIndex(Direction d)const
{
    switch (d)
    {
        case UP: return 0;
        case RIGHT: return m_board.Size() -1;
        case DOWN: return m_board.Size() -1;
        case LEFT: return 0;
    }
}

void Game::IncreaseIndex(Direction d, unsigned short &i)const
{
    switch (d) 
    {
        case UP: i++;break;
        case RIGHT: i--;break;
        case DOWN: i--;break;
        case LEFT: i++;break;
    }
}

void Game::DecreaseIndex(Direction d, unsigned short &i)const
{
    switch (d) 
    {
        case UP: i--;break;
        case RIGHT: i++;break;
        case DOWN: i++;break;
        case LEFT: i--;break;
    }
}

unsigned short Game::GetTileValue(Direction d, unsigned short index, unsigned short segment)const
{
    switch (d)
    {
        case UP: return m_board.GetTile(index,segment);
        case RIGHT: return m_board.GetTile(segment,index);
        case DOWN: return m_board.GetTile(index, segment);
        case LEFT: return m_board.GetTile(segment, index);
    }
}

void Game::SetTileValue(Direction d, unsigned short index, unsigned short segment, unsigned short val)
{
    switch (d)
    {
        case UP: m_board.SetTile(index, segment, val); break;
        case RIGHT: m_board.SetTile(segment,index, val); break;
        case DOWN: m_board.SetTile(index, segment, val); break;
        case LEFT: m_board.SetTile(segment, index, val); break;
    }
}