#include "GameManager.h"

GameManager::GameManager()
{
	
}

void GameManager::SetCursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GameManager::MapRender()
{
	for (auto x = 0; x < WIDTH; x++)
	{
		for (auto y = 0; y < HEIGHT; y++)
		{
			switch (map[y][x])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				ChangeColor(Green);
				cout << "бс";
				break;
			default:
				break;
			}
		}
	}
	
}

void GameManager::ChangeColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GameManager::HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
