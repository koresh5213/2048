#include "Game.h"
#include <iostream>
#include <random>

using namespace std;

Game::Game(unsigned long size, unsigned long spice)
: m_board(size)
, m_spiceSize(spice)
, m_score(0)
, m_gameOver(false)
, m_numTiles(0)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    m_seed = std::mt19937 (rd()); //Standard mersenne_twister_engine seeded with rd()
    m_rnd = std::uniform_int_distribution<> (0, size-1);
    m_precetntage = std::uniform_int_distribution<> (0, 99);

    BeginGame();
}

void Game::AddRandomTile()
{
    int randcol, randrow; 
    int four;

    do
    {
        randrow = m_rnd(m_seed);
        randcol = m_rnd(m_seed);
    } while ( m_board.GetTile(randrow, randcol) != 0 ); // possible bug? int to long

    four = m_precetntage(m_seed);

    if (four > 9)
    {
        m_board.SetTile(randrow, randcol, 2);
    }
    else
    {
        m_board.SetTile(randrow, randcol, 4);
    }
    
    m_numTiles++;
}

void Game::CheckForGameOver()
{
    if (!IsMoveLegal(UP) && !IsMoveLegal(DOWN) && !IsMoveLegal(LEFT) && !IsMoveLegal(RIGHT))
    {
        m_gameOver = true;
    }
}

void Game::SpiceUp()
{
    for (unsigned long i=0; i<m_spiceSize && (m_numTiles != m_board.Size() * m_board.Size()) ; ++i)
    {
        AddRandomTile();
    }
}

void Game::BeginGame()
{
    m_board.ClearBoard();
    m_numTiles = 0;
    m_score = 0;
    m_gameOver = false;
    AddRandomTile();
    for (unsigned long index = 0; index < m_board.Size()  / 2; ++index)
    {
        AddRandomTile();
    }
}

void Game::PrintState()const
{
    cout << "Score: " << m_score << endl;
    cout << "Free tiles: " << m_board.Size() *m_board.Size() - m_numTiles << endl;
    m_board.PrintBoard();
}

bool Game::Move(Direction d)
{
    unsigned long segment; // The row or col, depends on direction
    unsigned long next, partner;
    bool moved = false;

    for (segment = 0 ;segment < m_board.Size() ; ++segment)
    {
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
                    moved = true;
                    break;
                }

                if (GetTileValue(d, next, segment) == GetTileValue(d, partner, segment))
                {
                    SetTileValue(d, next, segment, 2 * GetTileValue(d, partner, segment));
                    SetTileValue(d, partner, segment, 0);

                    m_numTiles--;
                    m_score += GetTileValue(d, next, segment);
                    moved = true;
                    break;
                }

                if ( ((long)next-(long)partner) * ((long)partner-(long)next) == -1) // This means two different tiles with no '0's between then
                {
                    break;
                }

                IncreaseIndex(d, next);
                SetTileValue(d, next, segment, GetTileValue(d, partner, segment));
                SetTileValue(d, partner, segment, 0);
                DecreaseIndex(d,next);
                moved = true;
                break;
            }
        }
    }
    if (!moved)
    {
        return false;
    }
    SpiceUp();
    CheckForGameOver();
    return (!m_gameOver);
}

bool Game::IsMoveLegal(Direction d)const
{
    unsigned long segment; // The row or col, depends on direction
    unsigned long next, partner;

    for (segment = 0 ;segment < m_board.Size() ; ++segment)
    {
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
                    return true;
                }

                if (GetTileValue(d, next, segment) == GetTileValue(d, partner, segment))
                {
                    return true;
                }

                if ( ((long)next-(long)partner) * ((long)partner-(long)next) == -1) // This means two different tiles with no '0's between then
                {
                    break;
                }

                return true;
            }
        }
    }
    return false;
}

unsigned long Game::GetBeginIndex(Direction d)const
{
    switch (d)
    {
        case UP: return 0;
        case RIGHT: return m_board.Size() -1;
        case DOWN: return m_board.Size() -1;
        case LEFT: return 0;
    }
    return 0;
}

void Game::IncreaseIndex(Direction d, unsigned long &i)const
{
    switch (d) 
    {
        case UP: i++;break;
        case RIGHT: i--;break;
        case DOWN: i--;break;
        case LEFT: i++;break;
    }
}

void Game::DecreaseIndex(Direction d, unsigned long &i)const
{
    switch (d) 
    {
        case UP: i--;break;
        case RIGHT: i++;break;
        case DOWN: i++;break;
        case LEFT: i--;break;
    }
}

unsigned long Game::GetTileValue(Direction d, unsigned long index, unsigned long segment)const
{
    switch (d)
    {
        case UP: return m_board.GetTile(index,segment);
        case RIGHT: return m_board.GetTile(segment,index);
        case DOWN: return m_board.GetTile(index, segment);
        case LEFT: return m_board.GetTile(segment, index);
    }
    return 0;
}

void Game::SetTileValue(Direction d, unsigned long index, unsigned long segment, unsigned long val)
{
    switch (d)
    {
        case UP: m_board.SetTile(index, segment, val); break;
        case RIGHT: m_board.SetTile(segment,index, val); break;
        case DOWN: m_board.SetTile(index, segment, val); break;
        case LEFT: m_board.SetTile(segment, index, val); break;
    }
}

bool Game::GameOver()const
{
    return m_gameOver;
}

const Board Game::BoardState()const
{
    return m_board;
}

unsigned long Game::CurrentScore()const
{
    return m_score;
}