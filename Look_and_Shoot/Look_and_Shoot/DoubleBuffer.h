#pragma once
#include <iostream>
#include <Windows.h>

#define BufferWidth 62
#define BufferHeight 31

class DoubleBuffer  // ���� ����
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
	HANDLE hBuffer[2]; // ���� â �ΰ�
	int screenIndex;
public:
	void InitBuffer();
	void FlipBuffer();
	void ClearBuffer();
	void WriteBuffer(int x,int y, const char* shape , int color);
	void CloseBuffer();
};

