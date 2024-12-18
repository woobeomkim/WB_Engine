#include "wbPlayScene.h"
#include "wbGameObject.h"
#include "wbPlayer.h"
#include "wbTransform.h"
#include "wbSpriteRenderer.h"
#include "wbInput.h"
#include "wbSceneManager.h"
#include "wbTitleScene.h"
#include "wbObject.h"
#include "wbTexture.h"
#include "wbResources.h"
#include "wbPlayerScript.h"
#include "wbCamera.h"
#include "wbRenderer.h"
#include "wbAnimator.h"
#include "wbCat.h"
#include "wbCatScript.h"
#include "wbBoxCollider2D.h"
#include "wbCollisionManager.h"

namespace wb
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		CollisionManager::CollisionCheck(eLayerType::Player, eLayerType::Animal, true);

		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 440.0f));
		Camera* camearaComp = camera->AddComponent<Camera>();
		renderer::mainCamera = camearaComp;


		// 게임오브젝트 만들기전에 리소스들 전부 Load 해두면 좋다
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player /*, Vector2(100, 100) */ );
		//object::DontDestroyOnLoad(mPlayer);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		
		
		//BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		//collider->SetOffset(Vector2(-50.0f, -50.0f));

		CircleCollider2D* circleCollider = mPlayer->AddComponent<CircleCollider2D>();
		circleCollider->SetOffset(Vector2(-50.0f, -50.0f));


		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);


		playerAnimator->PlayAnimation(L"Idle", false);
		
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
	

		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal /*, Vector2(100, 100) */);

		CatScript* catSr = cat->AddComponent<CatScript>();
		
		catSr->SetOwner(cat);
		catSr->SetPlayer(mPlayer);

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
	
		//BoxCollider2D* BoxCatCollider = cat->AddComponent<BoxCollider2D>();
		//BoxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));

		CircleCollider2D* circleCatCollider = cat->AddComponent<CircleCollider2D>();
		circleCatCollider->SetOffset(Vector2(-50.0f, -50.0f));

		
		/*	catAnimator->CreateAnimation(L"DownWalk", catTex
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


		catAnimator->PlayAnimation(L"SitDown", false);*/
		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.1f);
		catAnimator->PlayAnimation(L"MushroomIdle", true);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);
		//camearaComp->SetTarget(cat);

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		/*
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, wcslen(str));
		*/
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		/*Transform* tr =
			bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));*/
	}
}