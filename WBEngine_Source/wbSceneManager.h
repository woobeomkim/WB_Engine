#pragma once
#include "wbScene.h"

namespace wb
{
	class SceneManager
	{
	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));
			return scene;
		}
		
		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }
		static Scene* GetDontDestroyOnLoad() { return mDontDestroyScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();
		
	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
		static Scene* mDontDestroyScene;
	};
}
