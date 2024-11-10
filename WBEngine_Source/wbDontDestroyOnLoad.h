#pragma once
#include "wbScene.h"


namespace wb
{
	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		virtual ~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		
	};
}
