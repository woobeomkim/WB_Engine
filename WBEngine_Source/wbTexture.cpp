#include "wbTexture.h"
#include "wbApplication.h"

// 해당 전역변수가 존재함을 알리는 키워드 extern
extern wb::Application application;

namespace wb::graphics
{
	Texture::Texture() : Resource(enums::eResourceType::Texture)
	{
	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		// bmp 일떄
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		// png 일떄

		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDc = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDc);
			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			
			if (mImage == nullptr)
				return S_FALSE;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}


		return S_OK;
	}
}