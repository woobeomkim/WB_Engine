#include "wbApplication.h"

namespace wb
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
	{
	}
	Application::~Application()
	{
	}
	void Application::Initailize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mSpeed += 0.0001f;
	
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}