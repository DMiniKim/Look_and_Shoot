#pragma once
#include "Object.h"
class Enemy :   public Object
{
private:
	bool activation;
public:
	Enemy();
	virtual void Move()override;
	
};

