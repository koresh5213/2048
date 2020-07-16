#ifndef GAME_ANALYSIS_H
#define GAME_ANALYSIS_H

class GameAnalysis
{
public:
GameAnalysis(unsigned long, unsigned long);

void AddGame(unsigned long score, bool failed = false);
void AddOther(GameAnalysis other);

private:
const unsigned long m_boardSize;
const unsigned long m_spiceSize;
unsigned long m_numberOfGames;
unsigned long m_failedGames;
unsigned long m_avScore;
unsigned long m_bestScore;
};

#endif