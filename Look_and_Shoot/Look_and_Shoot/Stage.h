#pragma once
#include "Scene.h"
class Stage : public Scene
{
public:
	class Player* player = nullptr;
public:
	virtual void Init() override;
	virtual void Update() override;
private:
	~Stage()
	{
		if (player != nullptr)
		{
			delete player;
			player = nullptr;
		}
	}
};

