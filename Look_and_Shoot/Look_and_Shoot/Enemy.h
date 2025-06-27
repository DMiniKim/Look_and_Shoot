#pragma once
#include "Object.h"
#include "Windows.h"
#include <cstdlib>
#include <ctime>

enum XYDirection { TOPTOBOT,BOTTOTOP,LEFTTORIGHT,RIGHTTOLEFT,DEFAULT, };

class Enemy :   public Object
{
private:
	bool IsHit;
	bool IsVisual;
	XYDirection xyDir;
	int prevX;
	int prevY;

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
	void Disappear(int _x, int _y);
	int GetX();
	int GetY();
	int GetPrevX();
	int GetPrevY();
};

