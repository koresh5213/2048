#include "StrategyRunner.h"
#include "Game.h"

using namespace std;

StrategyRunner::StrategyRunner(Strategy* const s)
:m_strtgy(s)
,m_toltrance(40)
{}

bool StrategyRunner::RunSingleGame(unsigned long boardSize, unsigned long SpiceSize)
{
    Direction d;
    Game g(boardSize, SpiceSize);
    // Tolrance: how many repeated tries to get valid move before declaring failed game?
    unsigned long tol;

    while (!g.GameOver())
    {
        tol = m_toltrance;
        while(1)
        {
            if (tol == 0)
            {
                m_analysis.AddSingleGame(boardSize, SpiceSize, g.CurrentScore(), true);
                return false;
            }

            if (g.GameOver()) break;

            d = m_strtgy->GetMove(g.BoardState());

            if (!g.Move(d))
            {
                tol--;
                continue;
            }
            else 
            {
                break;
            }
        }
    }

    m_analysis.AddSingleGame(boardSize, SpiceSize, g.CurrentScore(), false);
    return true;
}

string StrategyRunner::GetAnalyze()const
{
    return m_analysis.GetAnalysis();
}

void StrategyRunner::RunPlan(unsigned long size, unsigned long spice, unsigned long amount)
{
    for (unsigned long index = 0; index<amount; ++index)
    {
        RunSingleGame(size, spice);
    }
}