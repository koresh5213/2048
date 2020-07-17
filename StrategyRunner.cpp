#include "StrategyRunner.h"
#include "Game.h"

using namespace std;

StrategyRunner::StrategyRunner(Strategy* const s)
:m_strtgy(s)
,m_toltrance(10)
{}

bool StrategyRunner::RunSingleGame(unsigned long boardSize, unsigned long SpiceSize)
{
    Direction d;
    Game g(boardSize, SpiceSize);
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

            d = m_strtgy->GetMove(g.BoardState());

            if (!g.Move(d))
            {
                tol--;
                continue;
            }
            else break;
        }
    }

    m_analysis.AddSingleGame(boardSize, SpiceSize, g.CurrentScore(), false);
    return true;
}

string StrategyRunner::GetAnalyze()const
{
    return m_analysis.GetAnalysis();
}