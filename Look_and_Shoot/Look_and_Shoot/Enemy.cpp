#include "Enemy.h"
#include "DoubleBuffer.h"
#include "Bullet.h"
#include "Player.h"
#include <algorithm>


void Enemy::Init()
{
	x = 7;
	y = 7;
	shape = "��";

	xyDir= DEFAULT;
}

void Enemy::Update()
{
	prevX = x;	//�浹 �˻�� 
	prevY = y;	


	if (IsVisual && (xyDir !=DEFAULT))
	{
		switch (xyDir)		// ��ǥ�� ���� ���� ���� ����
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
		DoubleBuffer::GetInstance()->WriteBuffer(x, y, shape, 4);
	}

	Disappear(x,y);
	
}

void Enemy::Create(XYDirection dir)
{
	
	xyDir = dir;
	SetDir();

}

void Enemy::SetDir()
{
	switch (xyDir)
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
}


void Enemy::Disappear(int _x,int _y)
{
	if (((this->x < 17) &&(this->x > 13)) && ( (this->y >13) && (this->y<17) ) ) // player��ó���� ������� �����ؾ���
	{
		if (Player::hp > 0)
		{
			DoubleBuffer::GetInstance()->WriteBuffer(7, 7, "  ", 0);
			IsVisual = false;
			(Player::hp)--;
			return;
		}
		else
		{
			return;
		}
	}
	else
	{

		if (Player::bullet == nullptr) return; // ������ġ

		for (auto i = 0; i < MAX_BULLETCOUNT; i++)
		{

			Bullet& b = Player::bullet[i];

			if (b.IsActivate)
			{
				int bulletPrevX = b.GetPrevX();
				int bulletPrevY = b.GetPrevY();

				int bulletCurrX = b.GetX();
				int bulletCurrY = b.GetY();

				int enemyPrevX = prevX;
				int enemyPrevY = prevY;

				int enemyCurrX = x;
				int enemyCurrY = y;

				bool isXCrossed =
					(min(bulletPrevX, bulletCurrX) <= max(enemyPrevX, enemyCurrX)) &&
					(max(bulletPrevX, bulletCurrX) >= min(enemyPrevX, enemyCurrX));

				bool isYCrossed =
					(min(bulletPrevY, bulletCurrY) <= max(enemyPrevY, enemyCurrY)) &&
					(max(bulletPrevY, bulletCurrY) >= min(enemyPrevY, enemyCurrY));

				if (isXCrossed && isYCrossed)
				{
					// Bullet �Ҹ�
					b.Disappear(bulletCurrX, bulletCurrY);

					// Enemy �Ҹ�
					DoubleBuffer::GetInstance()->WriteBuffer(x, y, "  ", 0);
					IsVisual = false;

					return;
				}
			}
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
