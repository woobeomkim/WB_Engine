#include "wbToolScene.h"
#include "wbObject.h"
#include "..\WBEngine_Window\wbTile.h"
#include "wbTileMapRenderer.h"
#include "wbResources.h"
#include "wbTexture.h"
#include "wbCamera.h"
#include "wbRenderer.h"
#include "wbInput.h"

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

		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			Vector2 pos = Input::GetMousePosition();
			int indexX = pos.x / TileMapRenderer::TileSize.x;
			int indexY = pos.y / TileMapRenderer::TileSize.y;


			Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

			tile->SetPosition(indexX, indexY);
		}
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// 그리드 그리기

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, TileMapRenderer::TileSize.x * i, 0, nullptr);
			LineTo(hdc, TileMapRenderer::TileSize.x * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, TileMapRenderer::TileSize.y * i ,nullptr);
			LineTo(hdc, 1000, TileMapRenderer::TileSize.y * i);
		}
	}
	void ToolScene::OnEnter()
	{
	}
	void ToolScene::OnExit()
	{
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		wb::graphics::Texture* texture
			= wb::Resources::Find<wb::graphics::Texture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}