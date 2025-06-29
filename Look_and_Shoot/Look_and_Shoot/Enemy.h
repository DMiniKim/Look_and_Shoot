#pragma once
#include "Object.h"
#include "Windows.h"


enum XYDirection { TOPTOBOT,BOTTOTOP,LEFTTORIGHT,RIGHTTOLEFT,DEFAULT, };

class Enemy :   public Object
{
private:
	XYDirection xyDir;
	int prevX;
	int prevY;
public:
	bool IsVisual;
public:
	Enemy()
	{
		IsVisual = false;
	}
	virtual void Init() override;
	virtual void Update() override;
	
	void Create(XYDirection dir);
	void SetDir();
	
	void Disappear(int _x, int _y);
	int GetX();
	int GetY();
	int GetPrevX();
	int GetPrevY();
};

