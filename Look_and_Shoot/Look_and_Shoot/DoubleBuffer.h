#pragma once
#include <iostream>
#include <Windows.h>

#define BufferWidth 62
#define BufferHeight 31

class DoubleBuffer  // 연출 감독
{
private:
	static DoubleBuffer* instance;
public:
	static DoubleBuffer* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new DoubleBuffer;
		}
		return instance;
	}
private:
	HANDLE hBuffer[2]; // 버퍼 창 두개
	int screenIndex;
public:
	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x,int y, const char* shape , int color);
	void CloseBuffer();
};

