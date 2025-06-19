#include "Player.h"

Player::Player()
{
	if (bullet != nullptr)
	{
		bullet = nullptr;
	}
	shape = "■";
}

int& Player::GetPlayerX()
{
	return x;
}

int& Player::GetPlayerY()
{
	return y;
}

void Player::SetPlayerXY(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Player::Move()
{
	// 이동 관련 클래스에서 여기가져와서 적용
}
