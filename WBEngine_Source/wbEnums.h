#pragma once

namespace wb::enums
{

	enum class eComponentType
	{
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End
	};

	enum class eLayerType
	{
		None,
		BackGround,
		// Tree
		// character
		Animal,
		Player,
		Particle,
		Max = 16,
	};


	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};

	enum class eColliderType
	{
		Rect2D,
		Circle2D,
		End
	};
}