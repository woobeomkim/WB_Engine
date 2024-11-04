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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 440.0f));
		Camera* camearaComp = camera->AddComponent<Camera>();
		renderer::mainCamera = camearaComp;
		//camera->AddComponent<PlayerScript>();


		// 게임오브젝트 만들기전에 리소스들 전부 Load 해두면 좋다
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle /*, Vector2(100, 100) */ );
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		
		mPlayer->AddComponent<PlayerScript>();
		//bg->AddComponent<PlayerScript>();
		
		/*
		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);
		
		animator->PlayAnimation(L"CatFrontMove", true);*/

		
		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"RightWalk", packmanTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"UpWalk", packmanTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"LeftWalk", packmanTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"SitDown", packmanTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"Grooming", packmanTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);


		animator->PlayAnimation(L"SitDown", false);
		
		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);

		/*sr->SetTexture(packmanTexture);*/

		// 게임오브젝트 만들기전에 리소스들 전부 Load 해두면 좋다
		//GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Player /*, Vector2(100, 100) */);
		//SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetName(L"SR");
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		////bg->AddComponent<PlayerScript>();

		//graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		//bgSr->SetTexture(bgTexture);


		/*graphics::Texture* tex = new graphics::Texture();
		tex->Load(L"C:\\Users\\woobu\\source\\repos\\Editor_Window\\Resources\\CloudOcean.png");
	*/


		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal /*, Vector2(100, 100) */);
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->SetSize(Vector2(3.0f, 3.0f));*/

		cat->AddComponent<CatScript>();
		//bg->AddComponent<PlayerScript>();

		/*
		graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);

		animator->PlayAnimation(L"CatFrontMove", true);*/


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

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);

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