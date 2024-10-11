#include "wbGameObjectRed.h"

namespace wb
{
	GameObjectRed::GameObjectRed()
	{
	}
	GameObjectRed::~GameObjectRed()
	{
	}
	void GameObjectRed::Update()
	{
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObjectRed::LateUpdate()
	{
	}
	void GameObjectRed::Render(HDC hdc)
	{
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		Ellipse(hdc, 600 + mX, 600 + mY, 700 + mX, 700 + mY);
		DeleteObject(redPen);
		SelectObject(hdc, oldPen);
	}
}