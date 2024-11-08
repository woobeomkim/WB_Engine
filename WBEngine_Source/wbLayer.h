#pragma once
#include "wbEntity.h"
#include "CommonInclude.h"
#include "wbGameObject.h"

namespace wb
{ 
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		const std::vector<GameObject*>& GetGameObjects() { return mGameObjects; }

		void AddGameObject(GameObject* gameObject);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}
