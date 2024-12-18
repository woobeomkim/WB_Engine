#pragma once
#include "CommonInclude.h"
#include "wbMisiile.h"
#include "wbComponent.h"
//#include "wbObject.h"

namespace wb
{
	class GameObject
	{
	public:
		//friend void object::Destroy(GameObject* obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			comp->Initialize();
			
			mComponents[(UINT)comp->GetType()] = comp;
			
			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

		eState GetState()
		{
			return mState;
		}

		void SetActive(bool power)
		{
			if (power == true)
				mState = eState::Active;
			else
				mState = eState::Paused;
		}

		bool IsActive()
		{
			return mState == eState::Active;
		}

		bool IsDead()
		{
			return mState == eState::Dead;
		}

		void SetLayerType(enums::eLayerType layerType) { mLayerType = layerType; }
		enums::eLayerType GetLayerType() { return mLayerType; }

		void death() { mState = eState::Dead; }
	private:
		void initializeTransform();
		
	private:
		// 게임 오브젝트의 좌표
		eState mState;
		std::vector<Component*> mComponents;
		enums::eLayerType mLayerType;
	};
}
