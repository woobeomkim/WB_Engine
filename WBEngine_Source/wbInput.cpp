#include "wbInput.h"
#include "wbApplication.h"

extern wb::Application application;

namespace wb
{
	std::vector<Input::Key> Input::Keys = {};
	math::Vector2 Input::mMousePoistion = math::Vector2::One;

	int ASCII[(int)eKeyCode::End] =
	{
		'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,VK_SPACE,
	VK_LBUTTON,VK_MBUTTON ,VK_RBUTTON,
	};
	void Input::Initialize()
	{
		createKeys();
	}
	void Input::Update()
	{	
		updateKeys();
	}
	void Input::createKeys()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.KeyCode = (eKeyCode)i;
			key.state = eKeyState::None;
			Keys.push_back(key);
		}
	}
	void Input::updateKeys()
	{
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				updateKey(key);
			});
	}
	void Input::updateKey(Key& key)
	{
		if (GetFocus())
		{
			if (isKeyDown(key.KeyCode))
				updateKeyDown(key);
			else
				updateKeyUp(key);
			getMousePositionByWindow();
		}
		else
		{
			clearKeys();
		}
	}
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeyDown(Key& key)
	{
		if (key.bPressed)
			key.state = eKeyState::Pressed;
		else
			key.state = eKeyState::Down;
		key.bPressed = true;
	}
	void Input::updateKeyUp(Key& key)
	{
		if (key.bPressed)
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;
		key.bPressed = false;
	}
	void Input::getMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(application.GetHwnd(), &mousePos);

		mMousePoistion.x = mousePos.x;
		mMousePoistion.y = mousePos.y;
	}
	void Input::clearKeys()
	{
		for (Key& key : Keys)
		{
			if (key.state == eKeyState::Down || key.state == eKeyState::Pressed)
				key.state = eKeyState::Up;
			else if (key.state == eKeyState::Up)
				key.state = eKeyState::None;

			key.bPressed = false;
		}
	}
}