#include "wbGameObject.h"
#include "wbInput.h"

namespace wb
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
	}
}