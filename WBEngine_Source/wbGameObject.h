#pragma once
#include "CommonInclude.h"
#include "wbMisiile.h"
#include "wbComponent.h"

namespace wb
{
	class GameObject
	{
	public:
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
	private:
		void initializeTransform();
	private:
		// ���� ������Ʈ�� ��ǥ
		std::vector<Component*> mComponents;
	};
}
