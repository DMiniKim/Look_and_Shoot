#pragma once
#include "Object.h"
#include "Bullet.h"

#define MAX_BULLETCOUNT 10

enum Direction { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN };


class Player :public Object
{
private:
	const char* shapeArr[6];
public:
	static int hp;
	static int bulletCount;
	static Bullet* bullet;
public:
	
	virtual void Init() override;
	virtual void Update() override;
	int GetHP();
	~Player()
	{
		delete[] bullet;
		bullet = nullptr;
	}
	
};

