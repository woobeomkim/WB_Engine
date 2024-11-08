#include "wbCatScript.h"
#include "wbInput.h"
#include "wbTransform.h"
#include "wbTime.h"
#include "wbGameObject.h"
#include "wbAnimator.h"
#include "wbObject.h"

namespace wb
{
	CatScript::CatScript()
		: mState(eState::SitDown)
		, mAnimator(nullptr)
		, mRadian(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{

	}
	void CatScript::Update()
	{
		mDeathTime += Time::DeltaTime();

		if (mDeathTime > 6.0f)
		{
			//object::Destroy(GetOwner());
		}

		if (!mAnimator)
			mAnimator = GetOwner()->GetComponent<Animator>();
		switch (mState)
		{
		case wb::CatScript::eState::SitDown:
			sitDown();
			break;
		case wb::CatScript::eState::Walk:
			move();
			break;
		case wb::CatScript::eState::Sleep:
			break;
		case wb::CatScript::eState::LayDown:
			break;
		case wb::CatScript::eState::Attack:
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
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();

		if (mTime > 2.0f)
		{
			//object::Destroy(GetOwner());
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();

		Vector2 pos = tr->GetPosition();
		//pos.x -= 100.0f * Time::DeltaTime();
		
		//Vector2 mousePos = Input::GetMousePosition();
		
		// 마우스 위치 이동 (벡터 뺄셈 활용)
		/*Transform* plTr = mPlayer->GetComponent<Transform>();
		Vector2 playerPos = plTr->GetPosition();
		Vector2 dest = mDest - playerPos;
		pos += dest.normalize() * (100.0f * Time::DeltaTime());*/

		// 삼각함수를 통한 이동
		/*mRadian += 5.0f* Time::DeltaTime();
		pos += Vector2(1.0f,(1.0f*cosf(mRadian))).normalize() * (100.0f * Time::DeltaTime());
		*/
		
		
		// 마우스 위치 방향으로 회전후 마우스 위치 이동 (벡터 뺄셈 활용)
		Transform* plTr = mPlayer->GetComponent<Transform>();
		Vector2 playerPos = plTr->GetPosition();
		Vector2 dest = mDest - playerPos;
		dest.normalize();

		float rotDegree = Vector2::Dot(dest, Vector2::Right); // cos 세타
		rotDegree = acosf(rotDegree);
		
		rotDegree = ConvertDegree(rotDegree);

		pos += dest * (100.0f * Time::DeltaTime());

	
		//pos = (pos * 100.0f * Time::DeltaTime());
		tr->SetPosition(pos);

		/*if (mTime > 3.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;

			playWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}*/
		/*if (Input::GetKey(eKeyCode::Right))
		{
			mState = CatScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::Left))
			mState = CatScript::eState::Walk;

		if (Input::GetKey(eKeyCode::Up))
			mState = CatScript::eState::Walk;

		if (Input::GetKey(eKeyCode::Down))
			mState = CatScript::eState::Walk;*/

	}
	void CatScript::move()
	{

		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
			mTime = 0.0f;
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();

		translate(tr);


	}
	void CatScript::layDown()
	{

	}
	void CatScript::playWalkAnimationByDirection(eDirection dir)
	{
		/*catAnimator->CreateAnimation(L"DownWalk", catTex
	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
catAnimator->CreateAnimation(L"RightWalk", catTex
	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
catAnimator->CreateAnimation(L"UpWalk", catTex
	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
catAnimator->CreateAnimation(L"LeftWalk", catTex
	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);*/


		switch (dir)
		{
		case wb::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case wb::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case wb::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case wb::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case wb::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case wb::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case wb::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case wb::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}