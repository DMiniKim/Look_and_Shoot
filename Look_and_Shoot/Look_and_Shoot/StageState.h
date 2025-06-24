#pragma once

class Stage;

class StageState
{
public:
	virtual ~StageState() {}
	virtual void Update(Stage* stage) = 0;
};

