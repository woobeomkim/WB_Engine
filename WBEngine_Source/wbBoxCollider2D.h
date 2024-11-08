#pragma once
#include "wbCollider.h"

namespace wb
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		virtual ~BoxCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
		Vector2 mSize;
	};
}
