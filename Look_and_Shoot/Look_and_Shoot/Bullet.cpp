#include "Bullet.h"
#include "Player.h"
#include "DoubleBuffer.h"

void Bullet::Init()
{
	x = 15;
	y = 15;
	shapeArr[0] = "⊂";
	shapeArr[1] = "⊃";
	shapeArr[2] = "∩";
	shapeArr[3] = "∪";

}

void Bullet::Update()
{
	switch (bulletDir)
	{
	case 0:
		x -= 1;
		break;
	case 1:
		x += 1;
		break;
	case 2:
		y -= 1;
		break;
	case 3:
		y += 1;
		break;
	default:
		break;
	}

	if (x < 14 || y < 14 || x>16 || y>16) // 특정 범위를 벗어나면 
	{
		IsVisual = true; // 비주얼 활성화

	}

	if (IsVisual) // 비주얼이 켜지면
	{
		if (x < 14) // Left
		{
			DoubleBuffer::GetInstance()->WriteBuffer(x, y, shapeArr[0], 7);
		}
		if (x > 16) // Right
		{
			DoubleBuffer::GetInstance()->WriteBuffer(x, y, shapeArr[1], 7);
		}
		if (y < 14) // Up
		{
			DoubleBuffer::GetInstance()->WriteBuffer(x, y, shapeArr[2], 7);
		}
		if (y > 16) // Right
		{
			DoubleBuffer::GetInstance()->WriteBuffer(x, y, shapeArr[3], 7);
		}
	}
	Disappear(x, y);
}


void Bullet::Fire(int dir)
{
	bulletDir = dir;
	IsActivate = true;
	// 발사 방향에 따른 로직
	if (dir == DIR_LEFT){ x -= 1; }
	else if (dir == DIR_RIGHT){ x += 1; }
	else if (dir == DIR_UP) { y -= 1; }
	else if (dir == DIR_DOWN){ y += 1; }
	
}

void Bullet::Disappear(int _x, int _y)
{
	if (_x < 1 )
	{
		IsActivate = false;
		IsVisual = false;
		x = 15;
		y = 15;
	}
	else if (_y < 1)
	{
		IsActivate = false;
		IsVisual = false;
		x = 15;
		y = 15;
	}
	else if (_x > 58)
	{
		IsActivate = false;
		IsVisual = false;
		x = 15;
		y = 15;
	}
	else if (_y > 29)
	{
		IsActivate = false;
		IsVisual = false;
		x = 15;
		y = 15;
	}
}

