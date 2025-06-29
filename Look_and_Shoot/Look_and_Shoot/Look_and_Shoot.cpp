#include <iostream>
#include "Player.h"
#include "GameManager.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{
     
    srand((unsigned int)time(NULL));
    GameManager gamemanager;
    gamemanager.Init();
    gamemanager.Run();
    
    return 0;
}

