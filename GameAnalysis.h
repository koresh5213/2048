#ifndef GAME_ANALYSIS_H
#define GAME_ANALYSIS_H

#include <string>

class GameAnalysis
{
public:
    GameAnalysis(unsigned long, unsigned long);

    void AddGame(unsigned long score, bool failed = false);
    bool AddOther(GameAnalysis other); //Returns addition status. adding only same dimentions games
    std::string ToString()const;

    inline unsigned long GetBoardSize()const {return m_boardSize;}
    inline unsigned long GetSpiceSize()const {return m_spiceSize;}

private:
    const unsigned long m_boardSize;
    const unsigned long m_spiceSize;
    unsigned long m_numberOfGames;
    unsigned long m_failedGames;
    double m_avScore;
    unsigned long m_bestScore;
};

#endif