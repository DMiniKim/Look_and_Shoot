#include "Stage.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "Player.h"


//
//#######  #######    ##
//###  ##  ###  ##    ##
//     ##       ##    ##
//   ####  #######    ###
//     ##  ##         ###   
//###  ##  ###        ###
//#######  #######    ###


void Stage::Init()
{
	player = new Player;
	player->Init();
}

void Stage::Update()
{
	static bool isGameStart = false;

	// Player  해결 해야함
	for (auto x = 0; x < WIDTH; x++)
	{
		for (auto y = 0; y < HEIGHT; y++)
		{
			switch (map[y][x])
			{
			case 0:
				DoubleBuffer::GetInstance()->WriteBuffer(x, y, "  ", 13);
				break;
			case 1:
				DoubleBuffer::GetInstance()->WriteBuffer(x, y, "■", 13);
				break;
			default:
				break;
			}
		}
	}	
	player->Update();
}
