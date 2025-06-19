#pragma once
#include "Object.h"
class Bullet : public Object
{
private:
	bool activation;
public:
	Bullet();
	virtual void Move()override;
};

