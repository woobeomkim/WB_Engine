#include "wbPlayerScript.h"
#include "wbInput.h"
#include "wbTransform.h"
#include "wbTime.h"
#include "wbGameObject.h"
#include "wbAnimator.h"
#include "wbCat.h"
#include "wbResources.h"
#include "wbObject.h"
#include "wbCatScript.h"
#include "wbCollider.h"

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
	void PlayerScript::AttackEffect()
	{
		//Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal /*, Vector2(100, 100) */);

		//CatScript* catSrc = cat->AddComponent<CatScript>();

		//catSrc->SetPlayer(GetOwner());

		//graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		//Animator* catAnimator = cat->AddComponent<Animator>();
		//catAnimator->CreateAnimation(L"DownWalk", catTex
		//	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"RightWalk", catTex
		//	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"UpWalk", catTex
		//	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"LeftWalk", catTex
		//	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"SitDown", catTex
		//	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"Grooming", catTex
		//	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"LayDown", catTex
		//	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);


		//catAnimator->PlayAnimation(L"SitDown", false);

		//Transform* tr = GetOwner()->GetComponent<Transform>();

		//cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
		//cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		//Vector2 mousePos = Input::GetMousePosition();
		//catSrc->mDest = mousePos;
	}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}
	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal /*, Vector2(100, 100) */);

			CatScript* catSrc = cat->AddComponent<CatScript>();

			catSrc->SetPlayer(GetOwner());

			graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTex
				, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTex
				, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTex
				, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTex
				, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTex
				, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTex
				, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTex
				, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);


			catAnimator->PlayAnimation(L"SitDown", false);

			Transform* tr = GetOwner()->GetComponent<Transform>();

			cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = Input::GetMousePosition();
			catSrc->mDest = mousePos;
			/*mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater",false);*/
			
			//Vector2 mousePos = Input::GetMousePosition();
		}

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