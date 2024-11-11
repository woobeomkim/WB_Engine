#include "wbTileMapRenderer.h"
#include "wbGameObject.h"
#include "wbTransform.h"
#include "wbTexture.h"
#include "wbRenderer.h"
#include "wbCamera.h"

namespace wb
{
	TileMapRenderer::TileMapRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
		, mIndex(Vector2::Zero)
		, mTileSize(16.0f,16.0f)
	{
	}
	TileMapRenderer::~TileMapRenderer()
	{
	}
	void TileMapRenderer::Initialize()
	{
	}
	void TileMapRenderer::Update()
	{
	}
	void TileMapRenderer::LateUpdate()
	{
	}
	void TileMapRenderer::Render(HDC hdc)
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
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x
					, pos.y
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x
					, pos.y
					, mTileSize.x * mSize.x * scale.x
					, mTileSize.y * mSize.y * scale.y
					, mTexture->GetHdc()
					, mIndex.x * mTileSize.x, mIndex.y * mTileSize.y
					, mTileSize.x
					, mTileSize.y
					, RGB(255, 0, 255));
			}
		}
		//else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		//{
		//	Gdiplus::Graphics graphics(hdc);

		//	graphics.TranslateTransform(pos.x, pos.y);
		//	graphics.RotateTransform(rot);
		//	graphics.TranslateTransform(-pos.x, -pos.y);

		//	Gdiplus::ImageAttributes imgAtt = {};

		//	imgAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

		//	graphics.DrawImage(mTexture->GetImag(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x * scale.x, mTexture->GetHeight() * mSize.y * scale.x)
		//		, 0, 0
		//		, mTexture->GetWidth()
		//		, mTexture->GetHeight()
		//		, Gdiplus::UnitPixel
		//		, nullptr/*&imgAtt*/);
		//}

	}

}