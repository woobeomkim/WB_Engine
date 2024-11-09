#include "wbCollider.h"
#include "wbScript.h"
#include "wbGameObject.h"

namespace wb
{
	UINT32 Collider::mCollisionID = 1;
	Collider::Collider()
		: Component(enums::eComponentType::Collider)
		, mID(mCollisionID++)
		, mSize(Vector2::One)
	{
	}
	Collider::~Collider()
	{
	}
	void Collider::Update()
	{
	}
	void Collider::LateUpdate()
	{
	}
	void Collider::Render(HDC hdc)
	{
	}
	void Collider::Initialize()
	{
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		Script* script = GetOwner()->GetComponent<Script>();
		script->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
	}
	void Collider::OnCollisionExit(Collider* other)
	{
	}
}