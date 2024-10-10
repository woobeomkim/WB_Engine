#pragma once
#include "CommonInclude.h"
#include "wbGameObject.h"

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
		
		//플레이어
		GameObject mPlayer;
	};
}
