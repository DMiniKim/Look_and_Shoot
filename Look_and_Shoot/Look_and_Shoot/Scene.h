#pragma once
#include <iostream>

using namespace std;

class Scene
{
public:
	virtual void Init() abstract;
	virtual void Update() abstract;

};

