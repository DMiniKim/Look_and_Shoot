#pragma once
#include "Object.h"
#include "Bullet.h"

enum Direction { DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN };


class Player :public Object
{
private:
	const char* shapeArr[6];
	Bullet* bullet;

public:
	virtual void Init() override;
	virtual void Update() override;
	
};

