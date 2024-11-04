#include "wbCat.h"
#include "wbInput.h"
#include "wbTransform.h"
#include "wbTime.h"

namespace wb
{
	Cat::Cat()
	{
	}
	Cat::~Cat()
	{
	}
	void Cat::Initialize()
	{
		GameObject::Initialize();
	}
	void Cat::Update()
	{
		GameObject::Update();

	}
	void Cat::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Cat::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}