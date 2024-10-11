#include "wbApplication.h"
#include "wbInput.h"

namespace wb
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr)
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
		mMonster.SetPosition(0, 0);

		Input::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		Input::Update();
		mPlayer.Update();
		mMonster.Update();
	}

	void Application::LateUpdate()
	{
	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mMonster.Render(mHdc);
	}
}