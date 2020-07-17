#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
    unsigned long ans;
    char ansc = 'n';
    cout << "Game size?" << endl;
    cin >> ans;
    bool moved = true;

    Game g(ans);
    
    do 
    {
        switch (ansc)
        {
            case 'W': case 'w':
                moved = g.Move(UP);
                break;
            case 'A': case 'a':
                moved = g.Move(LEFT);
                break;
            case 'S': case 's':
                moved = g.Move(DOWN);
                break;
            case 'D': case 'd':
                moved = g.Move(RIGHT);
                break;
            case 'R': case 'r':
                g.BeginGame();
                moved = true;
                break;
            
            
        }
        if (moved)
        {
            g.PrintState();
            cout << "======" << endl << "use WASD, R for restart" << endl;
        }
        else
        {
            if (g.GameOver())
            {
                cout << "Game uber" << endl;
            }
            else
            {
                cout << "Bad move" << endl;
            }
            
        }
        
        cin >> ansc;
    }
    while(ansc != 'Q' && ansc!='q');


    return 0;
}

