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
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT hegiht);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();
	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		//std::vector<GameObject*> mGameObjects;
	};
}
