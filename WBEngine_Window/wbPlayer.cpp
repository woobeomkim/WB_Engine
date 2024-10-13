#include "wbPlayer.h"
#include "wbInput.h"
#include "wbTransform.h"
#include "wbTime.h"

namespace wb
{
	Player::Player()
	{
	}
	Player::~Player()
	{
	}
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPos(pos);
		}
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}