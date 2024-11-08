#pragma once
#include "wbCollider.h"


namespace wb
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		virtual ~CircleCollider2D();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Initialize() override;
	
	private:
		float mRadius;
	};
}

