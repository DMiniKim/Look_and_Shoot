#include "Title.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "Player.h"

void Title::Init()
{
	cout << "Title Init";
}

void Title::Update()
{
	// Player  해결 해야함
	DoubleBuffer::GetInstance()->WriteBuffer(15, 15,"Title", 13);

	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}
}
