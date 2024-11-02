#include "wbSpriteRenderer.h"
#include "wbGameObject.h"
#include "wbTransform.h"
#include "wbTexture.h"
#include "wbRenderer.h"
#include "wbCamera.h"

namespace wb
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		,mTexture(nullptr)
		,mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr) // 텍스쳐 세팅 해주세요!
			assert(false);
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CalculatePosition(pos);
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();


		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth() *mSize.x * scale.x, mTexture->GetHeight() *mSize.y * scale.y,
				mTexture->GetHdc(), 0, 0,
				mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphics(hdc);
			
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			Gdiplus::ImageAttributes imgAtt = {};
			
			imgAtt.SetColorKey(Gdiplus::Color(200,200,200), Gdiplus::Color(255, 255, 255));
			
			graphics.DrawImage(mTexture->GetImag(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x * scale.x , mTexture->GetHeight() * mSize.y * scale.x)
				,0,0
				,mTexture->GetWidth()
				,mTexture->GetHeight()
				,Gdiplus::UnitPixel
				,nullptr/*&imgAtt*/);
			
			
		}
	
	}

}