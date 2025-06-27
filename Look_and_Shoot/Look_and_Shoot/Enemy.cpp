#include "Enemy.h"
#include "DoubleBuffer.h"
#include "Bullet.h"
#include "Player.h"
#include <algorithm>


void Enemy::Init()
{
	x = 7;
	y = 7;
	shape = "▦";
	Create();
	srand((unsigned int)time(NULL));
	xyDir= DEFAULT;
}

void Enemy::Update()
{
	prevX = x;
	prevY = y;

	Create();

	if (IsVisual && !DEFAULT)
	{
		switch (xyDir)
		{
		case TOPTOBOT: y++;
			break;
		case BOTTOTOP: y--;
			break;
		case LEFTTORIGHT: x++;
			break;
		case RIGHTTOLEFT: x--;
			break;
		default:
			break;
		}
	}


	Disappear(x,y);
	
}

void Enemy::Create()
{
	int probability = rand() % 10000; // 1/1000 확률을 위함
	if (probability == 500) // 500이라는 0.01퍼센트의 확률 마다 생성
	{
		xyDir = (XYDirection)(rand() % 4);
		RandomDir(xyDir);
	}
}

void Enemy::RandomDir(XYDirection dir)
{
	switch (dir)
	{
	case TOPTOBOT:
		x = 15;
		y = 1;
		break;
	case BOTTOTOP:
		x = 15;
		y = 30;
		break;
	case LEFTTORIGHT:
		x = 1;
		y = 15;
		break;
	case RIGHTTOLEFT:
		x = 30;
		y = 15;
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

void Enemy::Disappear(int _x,int _y)
{
	for (auto i = 0; i < Player::bulletCount; i++)
	{	
		if (Player::bullet[i].IsActivate)
		{
			int;

		}
	}
}

int Enemy::GetX()
{
	return x;
}

int Enemy::GetY()
{
	return y;
}

int Enemy::GetPrevX()
{
	return prevX;
}

int Enemy::GetPrevY()
{
	return prevY;
}
