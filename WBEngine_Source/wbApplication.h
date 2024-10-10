#pragma once
#include "CommonInclude.h"

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

		float mSpeed;
		float mX;
		float mY;
	};
}
