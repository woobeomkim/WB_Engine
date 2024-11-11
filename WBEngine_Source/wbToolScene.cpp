#include "wbToolScene.h"
#include "wbObject.h"
#include "..\WBEngine_Window\wbTile.h"
#include "wbTileMapRenderer.h"
#include "wbResources.h"
#include "wbTexture.h"
#include "wbCamera.h"
#include "wbRenderer.h"

namespace wb
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 440.0f));
		Camera* camearaComp = camera->AddComponent<Camera>();
		renderer::mainCamera = camearaComp;

		Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
		TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
		tmr->SetSize(Vector2(3.0f, 3.0f));
		Scene::Initialize();
	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// 그리드 그리기

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 16 * 3 * i, 0, nullptr);
			LineTo(hdc, 16 * 3 * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, 16 * 3 * i ,nullptr);
			LineTo(hdc, 1000, 16 * 3 * i);
		}
	}
	void ToolScene::OnEnter()
	{
	}
	void ToolScene::OnExit()
	{
	}
}