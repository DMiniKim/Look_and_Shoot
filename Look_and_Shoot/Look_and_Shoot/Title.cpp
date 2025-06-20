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
	// Player  �ذ� �ؾ���
	DoubleBuffer::GetInstance()->WriteBuffer(15, 15,"Title", 13);

	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}
}
