#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

#define BufferWidth 62
#define BufferHeight 31

enum SCENE_ID
{
	TITLE,
	STAGE,
};

class SceneManager // 무대 감독
{
private:
	static SceneManager* instance;
public:
	static SceneManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager;
		}
		return instance;
	}
private:
	class Scene* scene = nullptr;
public:
	void SetScene(SCENE_ID id);
	void Init();
	void Update();
};

