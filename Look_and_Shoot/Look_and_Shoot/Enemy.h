#pragma once
#include "Object.h"
class Enemy :   public Object
{
private:
	
public:
	virtual void Init() override;
	virtual void Update() override;
	
};

