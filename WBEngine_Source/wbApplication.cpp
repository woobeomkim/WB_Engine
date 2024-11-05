#include "wbApplication.h"
#include "wbInput.h"
#include "wbTime.h"
#include "wbSceneManager.h"
#include "wbResources.h"

namespace wb
{
	Application::Application()
		: mHwnd(nullptr),
		mHdc(nullptr),
		mWidth(0),
		mHeight(0),
		mBackHdc(nullptr),
		mBackBitmap(nullptr)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initailize(HWND hwnd,UINT width, UINT height)
	{
		
		adjustWindowRect(hwnd,width,height);
		
		createBuffer(width, height);
		
		initializeEtc();

		SceneManager::Initialize();
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
		Time::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		// clear
		clearRenderTarget();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		
		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}
	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);

	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0,
			rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height)
	{// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// ����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}