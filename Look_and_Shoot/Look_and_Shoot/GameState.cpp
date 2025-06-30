#include "GameState.h"
#include "GameOverState.h"
#include "Enemy.h"

GameState::GameState()
{
	if (player == nullptr)	player = new Player;

	if (enemy == nullptr) enemy = new Enemy[10];

	player->Init();
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].Init();
	}
	score = 0;
}

void GameState::Update(Stage* stage)
{
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

	DoubleBuffer::GetInstance()->WriteBuffer(0, 0, "점수 : ", 6);
	for (auto i = 0; i < Player::hp; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(3+i, 0, "♡", 6);
	}
	//	if (player->GetHP() < 1)
	//	{
	//		stage->ChangeState(new GameOverState);
	//		stage->Update();
	//	}
	player->Update();
	int spawnChance = rand() % 10000;
	if (spawnChance < 500) // 1/10000확률로 생성
	{
		DoubleBuffer::GetInstance()->WriteBuffer(0, 30, "생성", 4);
		for (auto i = 0; i < MAX_ENEMY; i++)
		{
			if (!(enemy[i].IsVisual))
			{
				DoubleBuffer::GetInstance()->WriteBuffer(3, 30, "통과", 4);
				XYDirection dir = (XYDirection)(rand() % 4);
				enemy[i].Create(dir);
				break;
			}
		}
	}
	for (auto i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].Update();
	}

	//if (player->GetHP() < 1)
	//{	
	//	
	//	stage->ChangeState(new GameOverState);
	//	stage->Init();
	//	stage->Update(); 		
	//}
}

GameState::~GameState()
{
	delete[] enemy;
	enemy = nullptr;
	delete player;
	player = nullptr;
}
