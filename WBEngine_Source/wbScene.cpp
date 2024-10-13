#include "wbScene.h"

namespace wb
{
	Scene::Scene() : mLayers{}
	{
		mLayers.resize((UINT)eLayerType::Max);
		/*std::for_each(mLayers.begin(), mLayers.end(),
			[&](Layer*& layer)
		{
				layer = new Layer();
		});*/
		for (size_t i = 0; i < (UINT)eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}
	Scene::~Scene()
	{
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
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* gameObj, eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

}