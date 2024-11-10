#include "wbScene.h"

namespace wb
{
	Scene::Scene() : mLayers{}
	{
		createLayers();
	}
	Scene::~Scene()
	{
		for (auto* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Destroy();
		}
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* gameObj, enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::EraseGameObject(GameObject* gameObj)
	{
		enums::eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameObj);
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		/*std::for_each(mLayers.begin(), mLayers.end(),
			[&](Layer*& layer)
		{
				layer = new Layer();
		});*/
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

}