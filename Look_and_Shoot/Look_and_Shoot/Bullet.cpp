#include "Bullet.h"

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
	// 좌표 값에 따라 각 4 방향으로 가는 거 구현.
}
