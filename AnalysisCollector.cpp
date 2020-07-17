#include "AnalysisCollector.h"
using namespace std;

AnalysisCollector::AnalysisCollector()
{}

void AnalysisCollector::AddStatistic(GameAnalysis in)
{
    list<GameAnalysis>::iterator it;

    for (it=m_results.begin(); it !=m_results.end(); ++it)
    {
        if ( in.GetBoardSize() == it->GetBoardSize() && in.GetSpiceSize() == it->GetSpiceSize() )
        {
            it->AddOther(in);
            return;
        }    
    }
    
    m_results.push_back(in);
}

string AnalysisCollector::GetAnalysis()const
{
    string out;
    list<GameAnalysis>::const_iterator it;

    for (it=m_results.begin(); it !=m_results.end(); ++it)
    {
        out.append(it->ToString());
        out.append("\n");
    }
    return out;
}

void AnalysisCollector::AddSingleGame(unsigned long gameSize, unsigned long spiceSize, unsigned long score, bool falied)
{
    list<GameAnalysis>::iterator it;

    for (it=m_results.begin(); it !=m_results.end(); ++it)
    {
        if ( gameSize == it->GetBoardSize() && spiceSize == it->GetSpiceSize() )
        {
            it->AddGame(score, falied);
            return;
        }    
    }
    
    GameAnalysis ga(gameSize, spiceSize);
    ga.AddGame(score, falied);
    m_results.push_back(ga);
}