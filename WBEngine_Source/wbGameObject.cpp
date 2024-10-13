#include "wbGameObject.h"
#include "wbInput.h"
#include "wbTime.h"

namespace wb
{
	GameObject::GameObject() : mX(0), mY(0)
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Space))
		{
			mMisiile = new Misiile();
			mMisiile->SetPosition(mX , mY);
			
			if (mY < 0)
			{
				delete mMisiile;
				mMisiile = nullptr;
			}
		}

		if (mMisiile)
			mMisiile->Update();
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
		if(mMisiile)
			mMisiile->Render(hdc);
	}
}