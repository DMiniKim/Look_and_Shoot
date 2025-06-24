#pragma once
#include "StageState.h"
#include <Windows.h>

//��������  ��������    ���
//����  ���  ����  ���    ���
//     ���       ���    ���
//   ����   ��������    ����
//     ���  ���         ����   
//����  ���  ����        ����
//��������  ��������    ����
class CountDownState : public StageState
{
	const char* img[3][7] = {
	{
		"    ���      ",
		"    ���      ",
		"    ���      ",
		"    ����    ",
		"    ����    ",
		"    ����    ",
		"    ����    ",
	},
	{
		"��������",
		"����    ���",
		"        ���",
		"��������",
		"���          ",
		"����        ",
		"��������",
	},
	{
		"��������",
		"����    ���",
		"          ���",
		"      ����  ",
		"          ���",
		"����    ���",
		"��������"
	}
	};
	int countDown = 3;
	DWORD lastTick = 0;
public:
	CountDownState();
	void Update(Stage* stage) override;
};

