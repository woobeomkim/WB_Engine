#pragma once
#include "wbCollider.h"


namespace wb
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		virtual ~CircleCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	
	private:
		float mRadius;
	};
}

