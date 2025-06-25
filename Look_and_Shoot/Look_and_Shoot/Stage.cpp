#include "Stage.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "Player.h"
#include "CountDownState.h"



void Stage::Init()
{
	if (curState == nullptr)
	{
		curState = new CountDownState;
	}
}

void Stage::Update()
{
	if (curState)
	{
		curState->Update(this);
	}


	//static bool isGameStart = false;
	//
	//
	//for (auto x = 0; x < WIDTH; x++)
	//{
	//	for (auto y = 0; y < HEIGHT; y++)
	//	{
	//		switch (map[y][x])
	//		{
	//		case 0:
	//			DoubleBuffer::GetInstance()->WriteBuffer(x, y, "  ", 13);
	//			break;
	//		case 1:
	//			DoubleBuffer::GetInstance()->WriteBuffer(x, y, "бс", 13);
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//}	
	//player->Update();
}

void Stage::ChangeState(StageState* newstate)
{
	if (curState)
	{
		delete curState;
		curState = newstate;
	}
}
