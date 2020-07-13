#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
    unsigned short ans;
    char ansc = 'n';
    cout << "Game size?" << endl;
    cin >> ans;

    Game g(ans);
    
    do 
    {
        switch (ansc)
        {
            case 'W': case 'w':
                g.Move(UP);
                break;
            case 'A': case 'a':
                g.Move(LEFT);
                break;
            case 'S': case 's':
                g.Move(DOWN);
                break;
            case 'D': case 'd':
                g.Move(RIGHT);
                break;
            case 'R': case 'r':
                g.BeginGame();
                break;
            
            
        }
        g.PrintState();
        cout << "======" << endl << "use WASD, R for restart" << endl;
        cin >> ansc;
    }
    while(ansc != 'Q' && ansc!='q');


    return 0;
}

