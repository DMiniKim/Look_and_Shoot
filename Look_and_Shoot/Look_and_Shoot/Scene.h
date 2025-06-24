#pragma once
#include <iostream>

#define WIDTH 31
#define HEIGHT 31

using namespace std;

class Scene
{
public:
	virtual void Init() abstract;
	virtual void Update() abstract;

};

