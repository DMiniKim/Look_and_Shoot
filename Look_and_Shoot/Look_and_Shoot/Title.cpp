#include "Title.h"
#include "GameManager.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"
#include "Player.h"

void Title::Init()
{
	pressEnter = "Press Enter";

	shapeArr[0] = " __               _   ";
	shapeArr[1] = "|  |    ___  ___ | |_ ";
	shapeArr[2] = "|  |__ | . || . || '_|";
	shapeArr[3] = "|_____||___||___||_,_|";
	
	shapeArr[4] = " _____         _ ";
	shapeArr[5] = "|  _  | ___  _| |";
	shapeArr[6] = "|     ||   || . |";
	shapeArr[7] = "|__|__||_|_||___|";
	
	
	shapeArr[8]  = " _____  _              _   ";
	shapeArr[9]  = "|   __|| |_  ___  ___ | |_ ";
	shapeArr[10] = "|__   ||   || . || . ||  _|";
	shapeArr[11] = "|_____||_|_||___||___||_|  ";


}

void Title::Update()
{

	for (auto i = 0; i < 12; i++)
	{															
	    DoubleBuffer::GetInstance()->WriteBuffer(9, i + 9 , shapeArr[i],    9); // 타이틀 구현
	}
	
	DoubleBuffer::GetInstance()->WriteBuffer(13, 23, pressEnter, Yellow); // press enter 구현

	
	if (GetAsyncKeyState(VK_RETURN))
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}
}
