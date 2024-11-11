#pragma once
#include "wbSceneManager.h"
#include "wbPlayScene.h"
#include "wbTitleScene.h"
#include "wbToolScene.h"

namespace wb
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<ToolScene>(L"ToolScene");

		//SceneManager::CreateScene<PlayScene>(L"EndScene");

		SceneManager::LoadScene(L"ToolScene");
	}
}