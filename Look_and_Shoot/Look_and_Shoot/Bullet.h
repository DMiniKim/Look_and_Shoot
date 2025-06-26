#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	bool IsVisual = false;
	const char* shapeArr[4];
	int bulletDir;
public:
	bool IsActivate = false;
	virtual void Init() override;
	virtual void Update() override;
	
public:
	void Fire(int dir);
	void Disappear(int x, int y);

};

