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
			mComponents.push_back(comp);

			return comp;
		}

		template<typename T>
		T* GetComp()
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
		// ���� ������Ʈ�� ��ǥ
		std::vector<Component*> mComponents;
	};
}
