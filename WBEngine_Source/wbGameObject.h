#pragma once
#include "CommonInclude.h"

namespace wb
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

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
		// ���� ������Ʈ�� ��ǥ
		float mX;
		float mY;
	};
}
