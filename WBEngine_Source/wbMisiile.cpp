#include "wbMisiile.h"
#include "wbTime.h"

namespace wb
{
	Misiile::Misiile() : mX(0.0f),mY(0.0f)
	{
	}
	Misiile::~Misiile()
	{
	}
	void Misiile::Update()
	{
		const float speed = 100.0f;
		mY -= speed * Time::DeltaTime();
	}
	void Misiile::LateUpdate()
	{
	}
	void Misiile::Render(HDC hdc)
	{
		Ellipse(hdc, mX, mY, mX + 100, mY + 100);
	}
}