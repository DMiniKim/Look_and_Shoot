#pragma once
#include <iostream>
#include <Windows.h>

#include "SceneManager.h"
#include "DoubleBuffer.h"


enum Color
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White,
};

using namespace std;

class GameManager // °¨µ¶´Ô
{
private:
	SceneManager* sceneManager;
	DoubleBuffer* doubleBuffer;
public:
	GameManager();
	void Init();
	void Run();
	
};

