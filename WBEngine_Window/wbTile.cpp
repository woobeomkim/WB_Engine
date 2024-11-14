#include "wbTile.h"
#include "wbTransform.h"
#include "wbTileMapRenderer.h"

namespace wb
{
	Tile::Tile()
	{
	}
	Tile::~Tile()
	{
	}
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}
	void Tile::Update()
	{
		GameObject::Update();

	}
	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Tile::SetPosition(int x, int y)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = x * TileMapRenderer::TileSize.x;
		pos.y = y * TileMapRenderer::TileSize.y;
		
		tr->SetPosition(pos);
	}
}