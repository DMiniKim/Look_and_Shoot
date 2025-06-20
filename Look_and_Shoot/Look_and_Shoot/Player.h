#pragma once
#include "Object.h"
#include "Bullet.h"
class Player :public Object
{
private:
	Bullet* bullet;

public:
	virtual void Init() override;
	virtual void Update() override;
	
};

