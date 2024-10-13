#pragma once
#include "wbComponent.h"
#include "wbLayer.h"
#include "wbGameObject.h"
#include "wbScene.h"
#include "wbSceneManager.h"
#include "wbTransform.h"

namespace wb::object
{
	template<typename T>
	static T* Instantiate(wb::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template<typename T>
	static T* Instantiate(wb::enums::eLayerType type,math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}