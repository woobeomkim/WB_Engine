#pragma once
#include "wbComponent.h"
#include "wbAnimation.h"


namespace wb
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();
		
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	
		void CreateAnimation(const std::wstring& name
			,graphics::Texture* spriteSheet
			,Vector2 leftTop
			,Vector2 size
			,Vector2 offSet
			,UINT spriteLength
			,float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

	};
}
