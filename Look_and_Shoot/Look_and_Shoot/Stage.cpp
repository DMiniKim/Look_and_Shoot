#include "Stage.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "Player.h"

void Stage::Init()
{
	player = new Player;
	player->Init();
}

void Stage::Update()
{
	player->Update();
	// Player  �ذ� �ؾ���
	DoubleBuffer::GetInstance()->WriteBuffer(15, 15, "STAGE", 13);

	
}
