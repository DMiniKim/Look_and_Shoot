#include "Enemy.h"
#include "DoubleBuffer.h"	

void Enemy::Init()
{
	cout << "Enemey Init";
}

void Enemy::Update()
{
	DoubleBuffer::GetInstance()->WriteBuffer(x, y, shape, 15);
}
