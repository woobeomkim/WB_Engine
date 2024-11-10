#pragma once
#include "wbEntity.h"
#include "wbGameObject.h"
#include "wbLayer.h"

namespace wb 
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, enums::eLayerType type);
		void EraseGameObject(GameObject* gameObj);
		Layer* GetLayer(enums::eLayerType type) { return mLayers[(UINT)type]; }
	private:
		std::vector<Layer*> mLayers;
	};
}
