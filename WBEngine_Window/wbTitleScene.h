#pragma once
#include "..\\WBEngine_Source\\wbScene.h"

namespace wb
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		virtual ~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
