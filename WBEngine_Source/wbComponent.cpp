#include "wbComponent.h"

namespace wb
{
	Component::Component(enums::eComponentType type) :mType(type)
	{
	}
	Component::~Component()
	{
	}
	void Component::Initialize()
	{
	}
	void Component::Update()
	{
	}
	void Component::LateUpdate()
	{
	}
	void Component::Render(HDC hdc)
	{
	}
}