#include "GameState.h"
#include "GameOverState.h"
#include "Enemy.h"

GameState::GameState()
{
	if (player == nullptr)	player = new Player;

	if (enemy == nullptr) enemy = new Enemy[10];

	enemy->Init();
	player->Init();
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
	if (player->GetHP() <= 0)
	{
		stage->ChangeState(new GameOverState);
		stage->Update();
	}
	for (auto i = 0; i < MAX_ENEMY; i++)
	{
		enemy[i].Update();
	}

	player->Update();
	
	
	//stage->ChangeState(new GameOverState);
	
	//stage->Update(new GameOverState); 마찬가지
}

GameState::~GameState()
{
	delete player;
	player = nullptr;
}
