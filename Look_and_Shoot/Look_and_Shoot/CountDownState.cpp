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

	if (now - lastTick > 1000) // ���� �ð� - ���Žð� = 1000���� �̻��� �� ���� �� 1�ʸ��� ����
	{
		DoubleBuffer::GetInstance()->ClearBuffer();
		if (countDown > 0)		// ī��Ʈ�ٿ��� 3�̶� 3�� ����
		{
			int index = countDown - 1;
			for (auto i = 0; i < 7; i++)
			{
				DoubleBuffer::GetInstance()->WriteBuffer(12 + i, 12, img[index][i], 12);
				countDown--;
				lastTick = now; // lasttick ����
			}
		}
		else
		{
			stage->ChangeState(new GameState);
		}
	}
}
