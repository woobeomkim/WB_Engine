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

		void Initailize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;


		//플레이어
		GameObject mPlayer;
		GameObjectRed mMonster;
	};
}
