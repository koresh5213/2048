#include "GameAnalysis.h"
using namespace std;

GameAnalysis::GameAnalysis(unsigned long size, unsigned long spice)
: m_boardSize(size)
, m_spiceSize(spice)
, m_numberOfGames(0)
, m_failedGames(0)
, m_avScore(0)
, m_bestScore(0)
{
}

void GameAnalysis::AddGame(unsigned long score, bool failed)
{
    ++m_numberOfGames;

    if (failed)
    {
        ++m_failedGames;
    }

    //m_avScore = (m_avScore + (double)score) / (double)m_numberOfGames;
    m_avScore *= (m_numberOfGames - 1);
    m_avScore += score;
    m_avScore /= m_numberOfGames;

    if (score > m_bestScore)
    {
        m_bestScore = score;
    }
}

bool GameAnalysis::AddOther(GameAnalysis other)
{
    if (other.m_boardSize != m_boardSize || other.m_spiceSize != m_spiceSize)
    {
        return false;
    }

    if (other.m_bestScore > m_bestScore)
    {
        m_bestScore = other.m_bestScore;
    }

    m_avScore = (m_avScore + other.m_avScore) / (m_numberOfGames + other.m_numberOfGames);

    m_failedGames+=other.m_failedGames;

    m_numberOfGames+=other.m_numberOfGames;
    
    return true;
}

string GameAnalysis::ToString()const
{
    string ans = "Board size: ";
    ans.append(to_string(m_boardSize));
    ans.append("\n");

    ans.append("Spice size: ");
    ans.append(to_string(m_spiceSize));
    ans.append("\n");

    ans.append("Number of games: ");
    ans.append(to_string(m_numberOfGames));
    ans.append("\n");

    ans.append("Falled: ");
    ans.append(to_string(m_failedGames));
    ans.append("\n");

    ans.append("Avarage score: ");
    ans.append(to_string(m_avScore));
    ans.append("\n");

    ans.append("Best score: ");
    ans.append(to_string(m_bestScore));

    return ans;
}