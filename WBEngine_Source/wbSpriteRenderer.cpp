#include "wbSpriteRenderer.h"
#include "wbGameObject.h"
#include "wbTransform.h"

namespace wb
{
	SpriteRenderer::SpriteRenderer()
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComp<Transform>();
		
		int x = tr->GetX();
		int y = tr->GetY();
		
		Rectangle(hdc, x, y, 100 + x, 100 + y);
	}
}