#include "GameOverState.h"
#include "SceneManager.h"

GameOverState::GameOverState()
{

}

void GameOverState::Update(Stage* stage)
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
				DoubleBuffer::GetInstance()->WriteBuffer(x, y, "бс", 13);
				break;
			default:
				break;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(12, 12 + i, ui[i], 9);
		DoubleBuffer::GetInstance()->WriteBuffer(13, 15,over , 9);
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		// countdown
	}
	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		SceneManager::GetInstance()->SetScene(TITLE);
		SceneManager::GetInstance()->Init();
		SceneManager::GetInstance()->Update();
	}
}
