#pragma once
#include "CommonInclude.h"

namespace wb
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		Left,Right,Down,Up,Space,
		LButton, MButton ,RButton,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		
		__forceinline static bool GetKeyDown(eKeyCode key) { return Keys[(UINT)key].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode key) { return Keys[(UINT)key].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode key) { return Keys[(UINT)key].state == eKeyState::Pressed; }
		__forceinline static math::Vector2 GetMousePosition() { return mMousePoistion; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Key& key);
		
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Key& key);
		static void updateKeyUp(Key& key);
		static void getMousePositionByWindow();
		static void clearKeys();

	private:
		static std::vector<Key> Keys;
		static math::Vector2 mMousePoistion;
	};
}
