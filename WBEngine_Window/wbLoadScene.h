#pragma once
#include "wbSceneManager.h"
#include "wbPlayScene.h"

namespace wb
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");
		//SceneManager::CreateScene<PlayScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}