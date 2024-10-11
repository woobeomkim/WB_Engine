#pragma once
#include "CommonInclude.h"

namespace wb
{
	class GameObjectRed
	{
	public:
		GameObjectRed();
		~GameObjectRed();

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }
	private:
		// 게임 오브젝트의 좌표
		float mX = 0.0f;
		float mY = 0.0f;
	};
}
