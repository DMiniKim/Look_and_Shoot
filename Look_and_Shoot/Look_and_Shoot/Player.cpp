#include "Player.h"
#include "DoubleBuffer.h"

void Player::Init()
{
	x = 15;
	y = 15;
	shape = "��";
}

void Player::Update()
{
	// ����Ű ������ �ش� �������� Bullet �߻� ����.
	cout << "�߻�" <<endl;
	DoubleBuffer::GetInstance()->WriteBuffer(x, y, shape, 10);
}
