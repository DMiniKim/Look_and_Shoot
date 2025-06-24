#include <iostream>
#include "Player.h"
#include "GameManager.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

using namespace std;

int main()
{
     
    GameManager gamemanager;
    gamemanager.Init();
    gamemanager.Run();
    
    return 0;
}

