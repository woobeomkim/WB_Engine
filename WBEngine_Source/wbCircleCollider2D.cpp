#include "wbCircleCollider2D.h"
#include "wbTransform.h"
#include "wbGameObject.h"
#include "wbCamera.h"
#include "wbRenderer.h"

namespace wb
{
	CircleCollider2D::CircleCollider2D()
		:Collider(enums::eColliderType::Circle2D)
	{
	}
	CircleCollider2D::~CircleCollider2D()
	{
	}
	void CircleCollider2D::Initialize()
	{
	}
	void CircleCollider2D::Update()
	{
	}
	void CircleCollider2D::LateUpdate()
	{
	}
	void CircleCollider2D::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);
		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject((int)HOLLOW_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Vector2 rightBottom(pos.x + offset.x + 100 * GetSize().x, pos.y + offset.y + 100 * GetSize().y);

		Ellipse(hdc, pos.x + offset.x, pos.y + offset.y, rightBottom.x, rightBottom.y);

		SelectObject(hdc, oldBrush);
		//DeleteObject(transparentBrush);
		//StockObject라 삭제할필요가없다.

		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}