#include "wbPlayerScript.h"
#include "wbInput.h"
#include "wbTransform.h"
#include "wbTime.h"
#include "wbGameObject.h"
#include "wbAnimator.h"

namespace wb
{
	PlayerScript::PlayerScript()
		: mState(eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{

	}
	void PlayerScript::Update()
	{
		if(!mAnimator)
			mAnimator = GetOwner()->GetComponent<Animator>();
		switch (mState)
		{
		case wb::PlayerScript::eState::Idle:
			idle();
			break;
		case wb::PlayerScript::eState::Walk:
			move();
			break;
		
		case wb::PlayerScript::eState::Sleep:
			break;
		case wb::PlayerScript::eState::GiveWater:
			giveWater();
			break;

		case wb::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

		/*if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}*/
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater",false);
			
			Vector2 mousePos = Input::GetMousePosition();
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Left))
			pos.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::Up))
			pos.y -= 100.0f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::Down))
			pos.y += 100.0f * Time::DeltaTime();
	
		tr->SetPosition(pos);
		if (Input::GetKeyUp(eKeyCode::Right) || Input::GetKeyUp(eKeyCode::Left) || Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
		
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", true);
		}
	}
}