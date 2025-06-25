#pragma once
#include "Scene.h"
#include "GameManager.h"
#include "Player.h"

class StageState;

class Stage : public Scene
{

private:
	StageState* curState = nullptr;

public:
	virtual void Init() override;
	virtual void Update() override;
	void ChangeState(StageState* newstage);
private:
	~Stage()
	{
		if (curState != nullptr)
		{
			delete curState;
			curState = nullptr;
		}
	}
};

