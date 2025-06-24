#include "CountDownState.h"
#include "Stage.h"
#include "DoubleBuffer.h"
#include "GameState.h"



CountDownState::CountDownState()
{
	lastTick = GetTickCount64();
}

void CountDownState::Update(Stage* stage)
{

	DWORD now = GetTickCount64();

	if (now - lastTick > 1000) // 지금 시간 - 과거시간 = 1000보다 이상일 때 실행 즉 1초마다 실행
	{
		DoubleBuffer::GetInstance()->ClearBuffer();
		if (countDown > 0)		// 카운트다운이 3이라 3번 실행
		{
			int index = countDown - 1;
			for (auto i = 0; i < 7; i++)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(12 + i, 12, img[index][i], 12);
				countDown--;
				lastTick = now; // lasttick 갱신
			}
		}
		else
		{
			stage->ChangeState(new GameState);
		}
	}
}
