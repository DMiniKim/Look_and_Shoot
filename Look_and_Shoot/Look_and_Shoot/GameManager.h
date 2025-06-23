#pragma once
#include <iostream>
#include <Windows.h>
#define WIDTH 31
#define HEIGHT 31

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

class GameManager
{
public:
	
	GameManager();
	void SetCursor(int x, int y);

	void ChangeColor(int color);
	void HideCursor();
};

