#include "wbApplication.h"

namespace wb
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mSpeed(0.0f),
		mX(0.0f),
		mY(0.0f)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initailize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
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
	
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.001f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.001f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.001f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.001f;
		}
	}
	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		Rectangle(mHdc, 500+mX, 500+mY, 600+mX, 600+mY);
	}
}