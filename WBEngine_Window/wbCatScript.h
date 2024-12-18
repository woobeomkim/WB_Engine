#pragma once
#include "..\\WBEngine_Source\\wbScript.h"
#include "wbTransform.h"

namespace wb
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End
		};
		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(class GameObject* player) { mPlayer = player; }

		void OnCollisionEnter(class Collider* other) override;
		void OnCollisionStay(class Collider* other) override;
		void OnCollisionExit(class Collider* other) override;


		Vector2 mDest;

	private:
		void sitDown();
		void move();
		void layDown();

		void playWalkAnimationByDirection(eDirection dir);
		void translate(Transform* tr);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime = 0.0f;
		float mDeathTime = 0.0f;
		class GameObject* mPlayer;
		float mRadian;
	};
}
