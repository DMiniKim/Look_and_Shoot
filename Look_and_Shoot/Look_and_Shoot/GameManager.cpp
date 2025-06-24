#include "GameManager.h"


GameManager::GameManager()
{
	doubleBuffer = DoubleBuffer::GetInstance();
	sceneManager = SceneManager::GetInstance();
}

void GameManager::Init()
{
	doubleBuffer->InitBuffer();
	sceneManager->SetScene(TITLE);
}

void GameManager::Run()
{
    while (true)
    {
        sceneManager->Update();

        doubleBuffer->FlipBuffer();
        doubleBuffer->ClearBuffer();

        Sleep(16);
    }
    doubleBuffer->CloseBuffer();
}
