#pragma once
#include "Object.h"
class Bullet : public Object
{
private:
	bool activation = false;
	bool visualOnOff = false;
	const char* shapeArr[4];
public:
	virtual void Init() override;
	virtual void Update() override;
	

};

