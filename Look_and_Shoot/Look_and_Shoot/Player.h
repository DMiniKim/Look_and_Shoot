#pragma once
#include "Object.h"
#include "Bullet.h"
class Player :public Object
{
private:
	Bullet* bullet;
public:
	const char* shape;
public:
	Player();
	int& GetPlayerX();
	int& GetPlayerY();
	void SetPlayerXY(int _x, int _y);
	// shoot �Լ� 
	virtual void Move() override;
};

