#pragma once
#include "Object.h"
#include "Windows.h"
#include <cstdlib>
#include <ctime>

enum XYDirection { UP,DOWN,LEFT,RIGHT };

class Enemy :   public Object
{
private:
	bool IsHit;
	bool IsVisual;
	XYDirection xyDir;

public:
	Enemy()
	{
		IsHit = false;
		IsVisual = false;
	}
	virtual void Init() override;
	virtual void Update() override;
	
	void Create();
	void RandomDir(XYDirection dir);
	void SetEnemyXY(int _x, int _y, XYDirection dir);
	
};

