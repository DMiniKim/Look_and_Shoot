#include <iostream>
#include "Player.h"
#include "GameManager.h"
using namespace std;

int main()
{
    Player player;
    GameManager gamemanager;
    while (true)
    {
        system("cls");
        gamemanager.HideCursor();
        player.SetPlayerXY(30, 15);
        gamemanager.MapRender();
        gamemanager.SetCursor(player.GetPlayerX(), player.GetPlayerY());
        gamemanager.ChangeColor(White);
        cout << player.shape;
        Sleep(100);
    }
    
    return 0;
}

