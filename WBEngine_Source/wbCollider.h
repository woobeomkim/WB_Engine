#pragma once
#include "wbComponent.h"

namespace wb
{
	class Collider : public Component
	{
	public:
		Collider();
		virtual ~Collider();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Initialize() override;

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
	private:
		Vector2 mOffset;
	};
}
