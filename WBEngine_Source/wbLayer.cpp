#include "wbLayer.h"

namespace wb
{
	Layer::Layer() : mGameObjects{}
	{
		
	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			
			delete gameObj;
			gameObj = nullptr;
		}
	}
	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			gameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			//GameObject::eState state = gameObj->GetActive();
			//if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			//	continue;
			
			if (gameObj->IsActive() == false)
				continue;
			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			//GameObject::eState state = gameObj->GetActive();
			//if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			//	continue;
			
			if (gameObj->IsActive() == false)
				continue;
			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;
			//GameObject::eState state = gameObj->GetActive();
			//if (state == GameObject::eState::Paused || state == GameObject::eState::Dead)
			//	continue;
			
			if (gameObj->IsActive() == false)
				continue;
			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		/*for (std::vector<GameObject*>::iterator iter = mGameObjects.begin(); iter != mGameObjects.end(); )
		{
			GameObject::eState active = (*iter)->GetState();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;
				continue;
			}
			else
				iter++;
		}*/

		std::vector<GameObject*> deleteObjects = {};
		findDeadGameObjects(deleteObjects);
		eraseDeadGameObject();
		deleteGameObjects(deleteObjects);

	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;
		mGameObjects.push_back(gameObject);
	}
	void Layer::EraseGameObject(GameObject* gameObject)
	{
		// std::erase() iter �־��༭ �ش� ���ͷ����Ϳ� ���� ��ü ����


		// ������ ���ΰ͸� ����
		std::erase_if(mGameObjects,
			[=](GameObject* gameObj)
			{
				return gameObj == gameObject;
			});
	}


	void Layer::findDeadGameObjects(OUT std::vector<GameObject*>& gameObjs)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			GameObject::eState active = gameObj->GetState();
			if (active == GameObject::eState::Dead)
				gameObjs.push_back(gameObj);
		}
	}

	void Layer::deleteGameObjects(std::vector<GameObject*> deleteObjs)
	{
		for (GameObject* obj : deleteObjs)
		{
			delete obj;
			obj = nullptr;
		}
	}

	void Layer::eraseDeadGameObject()
	{
		std::erase_if(mGameObjects,
			[](GameObject* gameObj)
			{
				return (gameObj)->IsDead();
			});
	}
}