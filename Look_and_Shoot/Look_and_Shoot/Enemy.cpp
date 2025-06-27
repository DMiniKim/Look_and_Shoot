#include "Enemy.h"
#include "DoubleBuffer.h"



void Enemy::Init()
{
	x = 7;
	y = 7;
	shape = "▦";
	Create();
	srand((unsigned int)time(NULL));
	xyDir= UP;
}

void Enemy::Update()
{
	Create();


	//DoubleBuffer::GetInstance()->WriteBuffer(x, y, shape, 4);
}

void Enemy::Create()
{
	int probability = rand() % 1000; // 1/1000 확률을 위함
	if (probability == 500) // 500이라는 0.1퍼센트의 확률 마다 생성
	{
		xyDir = (XYDirection)(rand() % 4);
		RandomDir(xyDir);
	}
}

void Enemy::RandomDir(XYDirection dir)
{
	switch (dir)
	{
	case UP:
		x = 15;
		y = 1;
		break;
	case DOWN:
		x = 15;
		y = 30;
		break;
	case LEFT:
		x = 1;
		y = 15;
		break;
	case RIGHT:
		x = 1;
		y = 30;
		break;
	default:
		break;
	}
	IsVisual = true;
	SetEnemyXY(x, y,dir);
}

void Enemy::SetEnemyXY(int _x , int _y, XYDirection dir)
{
	if (IsVisual)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(x, y, shape, 4);
	}
}
