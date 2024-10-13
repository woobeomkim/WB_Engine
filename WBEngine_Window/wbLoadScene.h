#pragma once
#include "wbSceneManager.h"
#include "wbPlayScene.h"
#include "wbTitleScene.h"

namespace wb
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"EndScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}