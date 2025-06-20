#include "Player.h"
#include "DoubleBuffer.h"

void Player::Init()
{
	x = 15;
	y = 15;
	shape = "■";
}

void Player::Update()
{
	// 방향키 누르면 해당 방향으로 Bullet 발사 구현.
	cout << "발사" <<endl;
	DoubleBuffer::GetInstance()->WriteBuffer(x, y, shape, 10);
}
