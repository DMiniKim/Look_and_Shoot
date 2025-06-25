#include "Player.h"
#include "DoubleBuffer.h"
#include "Bullet.h"
Direction dir = DIR_LEFT;

void Player::Init()
{
	x = 15;
	y = 15;
	shapeArr[0] = "��";
	shapeArr[1] = "��";
	shapeArr[2] = "��";
	shapeArr[3] = "��";
	shapeArr[4] = "��";
	shapeArr[5] = "  ";
	// ������ ������ ���� ����� �������� �̷��� �غ�.
    bullet = nullptr;
    if (bullet == nullptr)
    {
        bullet = new Bullet[10];
    }
}

void Player::Update()
{
	
	// ����Ű ������ �ش� �������� Player ���� ����.
    
    // ���⸸ ����
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) dir = DIR_LEFT;
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) dir = DIR_RIGHT;
    if (GetAsyncKeyState(VK_UP) & 0x8000) dir = DIR_UP;
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) dir = DIR_DOWN;

    // �׸���
    for (int dx = 0; dx < 3; dx++)
    {
        for (int dy = 0; dy < 3; dy++)
        {
            int drawX = x - 1 + dx;
            int drawY = y - 1 + dy;

            if (dx == 1 && dy == 1)
            {
                // �߾ӿ� �÷��̾�
                DoubleBuffer::GetInstance()->WriteBuffer(drawX, drawY, shapeArr[0], 10);
            }
            else if ((dir == DIR_LEFT && dx == 0 && dy == 1) ||
                (dir == DIR_RIGHT && dx == 2 && dy == 1) ||
                (dir == DIR_UP && dx == 1 && dy == 0) ||
                (dir == DIR_DOWN && dx == 1 && dy == 2))
            {
                // �� ��ġ
                DoubleBuffer::GetInstance()->WriteBuffer(drawX, drawY, shapeArr[1 + dir], 10);
            }
            else
            {
                // �������� ��ĭ
                DoubleBuffer::GetInstance()->WriteBuffer(drawX, drawY, shapeArr[5], 10);
            }
        }
    }
}

int& Player::GetHP()
{
    return hp;
}
