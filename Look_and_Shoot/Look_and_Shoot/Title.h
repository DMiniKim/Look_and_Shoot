#pragma once
#include "Scene.h"


class Title : public Scene
{
private:

	const char* pressEnter;
	const char* shapeArr[12];
public:
	virtual void Init() override;
	virtual void Update() override;
};

