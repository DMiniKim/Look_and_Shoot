#include "SceneManager.h"
#include "Stage.h"
#include "Title.h"

SceneManager* SceneManager::instance = nullptr;

void SceneManager::SetScene(SCENE_ID id)
{
	if (scene != nullptr)
	{
		delete scene;
		scene = nullptr;
	}
	switch (id)
	{
	case TITLE:
		delete scene;
		scene = new Title;
		break;
	case STAGE:
		delete scene;
		scene = new Stage;
		break;
	default:
		break;
	}
	Init();
	Update();
}

void SceneManager::Init()
{
	scene->Init();
}

void SceneManager::Update()
{
	scene->Update();
}
