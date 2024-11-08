#include "wbTexture.h"
#include "wbApplication.h"
#include "wbResources.h"

// �ش� ���������� �������� �˸��� Ű���� extern
extern wb::Application application;

namespace wb::graphics
{
	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image)
			return image;

		image = new Texture();
		image->SetWidth(width);
		image->SetHeight(height);
		image->SetName(name);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject((int)HOLLOW_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Rectangle(image->mHdc, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);

		SelectObject(hdc, oldBrush);
		//DeleteObject(transparentBrush);
		//StockObject�� �������ʿ䰡����.

		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);


		Resources::Insert(name, image);
		return image;
	}
	Texture::Texture() : Resource(enums::eResourceType::Texture) , mbAlpha(false)
	{
	}
	Texture::~Texture()
	{
	}
	HRESULT Texture::Load(const std::wstring& path)
	{
		// bmp �ϋ�
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		// png �ϋ�

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

			if (info.bmBitsPixel == 32)
				mbAlpha = true;
			else if (info.bmBitsPixel == 24)
				mbAlpha = false;

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