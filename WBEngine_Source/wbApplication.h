#pragma once
#include "CommonInclude.h"
#include "wbGameObject.h"
#include "wbGameObjectRed.h"

namespace wb
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initailize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		
		//�÷��̾�
		GameObject mPlayer;
		GameObjectRed mMonster;
	};
}
