#include <iostream>
#include "Player.h"
#include "GameManager.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

using namespace std;

int main()
{
    DoubleBuffer::GetInstance()->InitBuffer();
    SceneManager::GetInstance()->SetScene(TITLE);
    Player player;  
    //GameManager gamemanager;
    while (true)
    {
        SceneManager::GetInstance()->Update();
        
        DoubleBuffer::GetInstance()->FlipBuffer();
        DoubleBuffer::GetInstance()->ClearBuffer();

        //gamemanager.HideCursor();
        //player.SetPlayerXY(30, 15);
        //gamemanager.MapRender();
        //gamemanager.SetCursor(player.GetPlayerX(), player.GetPlayerY());
        //gamemanager.ChangeColor(White);
        //cout << player.shape;
        Sleep(30);
    }
    DoubleBuffer::GetInstance()->CloseBuffer();
    return 0;
}

