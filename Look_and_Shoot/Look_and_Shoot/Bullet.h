#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	const char* shapeArr[4];
	int bulletDir;
public:
	int prevX;
	int prevY;
	bool IsHit = false;
	bool IsVisual = false;
	bool IsActivate = false;
	virtual void Init() override;
	virtual void Update() override;
	
public:
	void Fire(int dir);
	void Disappear(int x, int y,bool hit);
	int GetX();
	int GetY();
	int GetPrevX();
	int GetPrevY();

};

