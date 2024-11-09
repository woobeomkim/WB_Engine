#include "wbScript.h"
#include "wbCollider.h"
#include "wbComponent.h"

namespace wb
{
	Script::Script() : Component(enums::eComponentType::Script)
	{
	}
	Script::~Script()
	{
	}
	void Script::Initialize()
	{
	}
	void Script::Update()
	{
	}
	void Script::LateUpdate()
	{
	}
	void Script::Render(HDC hdc)
	{
	}
	void Script::OnCollisionEnter(Collider* otehr)
	{
	}
	void Script::OnCollisionStay(Collider* otehr)
	{
	}
	void Script::OnCollisionExit(Collider* otehr)
	{
	}
}