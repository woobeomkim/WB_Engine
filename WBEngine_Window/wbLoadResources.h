#pragma once

#include "..\\WBEngine_Source\\wbResources.h"
#include "..\\WBEngine_Source\\wbTexture.h"
namespace wb
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\Player.bmp");
		Resources::Load<graphics::Texture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
		//Resources::Load<graphics::Texture>(L"Bubble", L"..\\Resources\\Bubble.png");
		//Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\woobu\\source\\repos\\Editor_Window\\Resources\\CloudOcean.png");
		//Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\pacman-master\\img\\pacman\\0.png");
		//Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\pacman-master\\img\\map\\map_pure.png");
		//Resources::Load<graphics::Texture>(L"Chichken", L"..\\Resources\\chicken.bmp");
		//Resources::Load<graphics::Texture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");

	}
}