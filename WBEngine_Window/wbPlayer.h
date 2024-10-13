#pragma once
#include "..\\WBEngine_Source\\wbGameObject.h"

namespace wb
{ 
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

