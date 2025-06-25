#include "CountDownState.h"
#include "Stage.h"
#include "DoubleBuffer.h"
#include "GameState.h"



CountDownState::CountDownState()
{
	//lastTick = GetTickCount64();
}

void CountDownState::Update(Stage* stage)
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
	//DWORD now = GetTickCount64();

	

	for (int count = 3; count >= 0; count--)
	{
		if (count > 0)		// 카운트다운이 3이라 3번 실행
		{
			int index = count - 1;
			for (auto i = 0; i < 7; i++)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(12, 12 + i, img[index][i], 12);
			}
		}
		else if (count <= 0)
		{
			stage->ChangeState(new GameState);
			stage->Update();
		}
	}
	
}
